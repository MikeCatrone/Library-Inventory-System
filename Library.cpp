
#include "Library.h"
#include "Book.h"

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>



// Default constructor creates an empty map
Library::Library(){

}



// Destructor
Library::~Library(){}



//Get Map
std::map<std::string, Book> Library::getMap() const{
    return this->bookCollection;
}


// Add Book
void Library::addBook(Book book) {
    this->bookCollection.insert({book.getIsbn(), book});
}



// Display all books
void Library::displayBooks() const {

    std::string choice;

    // Looping through the book collection
    for (const auto& element : this->bookCollection) {

        element.second.display();
        std::cout << "\n";

    }

    std::cout << "Enter any key to exit:" << "\n";
    std::cin >> choice;
}





// Search a Book
void Library::searchBook() {

    std::string choice;
    std::string value;
    

    std::cout << "Choose a search option" << "\n";
    std::cout << "==========================" << "\n \n";
    std::cout << "1. ISBN" << "\n";
    std::cout << "2. Title" << "\n";
    std::cout << "3. Exit" << "\n";
    std::cin >> choice;


    // If choice 1, search by ISBN
    if(choice == "1") {
        std::cout << "Enter an ISBN: " << "\n";
        std::cin >> value;
        std::cout << "\n";

        auto it = std::find_if(this->bookCollection.begin(), this->bookCollection.end(),
            [&value](auto &n) {
                return n.first == value;
            }
        );

        if (it != this->bookCollection.end()) {
            std::cout << "Book Found!" << "\n";
            std::cout << "Book Keys: " << it->first << "\n";
            std::cout << "Book Title: " << it->second.getTitle() << "\n \n";

        } else {
            std::cout << "Sorry, book not found" << "\n";
        }



    // If choice 2, search by Title
    } else if(choice == "2") {
        std::cout << "Enter a Title: " << "\n";
        std::getline(std::cin >> std::ws, value);
        std::cout << "\n";

        auto it = std::find_if(this->bookCollection.begin(), this->bookCollection.end(),
            [&value](auto &n) {
                return n.second.getTitle() == value;
            }
        );

        
        if (it != this->bookCollection.end()) {
            std::cout << "BookFound!" << "\n";
            std::cout << "Book Key: " << it->first << "\n";
            std::cout << "Book Title: " << it->second.getTitle() << "\n \n";

        } else {
            std::cout << "Sorry, book not found" << "\n";
        }


    }else if(choice == "3") {
        return;
    }


    std::cout << "Enter any key to exit:" << "\n";
    std::cin >> choice;

    return;
}




// Edit a Book
void Library::editBook() {
    std::string targetIsbn = "";

    std::cout << "\nEnter the ISBN of the book to edit:" << "\n";
    std::cin >> targetIsbn;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    auto it = std::find_if(this->bookCollection.begin(), this->bookCollection.end(),
        [&targetIsbn](const auto &entry) {
            return entry.first == targetIsbn;
        }
    );


    if (it == this->bookCollection.end()) {
        std::cout << "No book found with ISBN: " << targetIsbn << "\n";
        return;
    }


    int fieldChoice = 0;

    std::cout << "\nEditing " << it->second.getTitle() << " (ISBN: " << it->first << ")\n";
    std::cout << "What field do you want to edit?" << "\n";
    std::cout << "1. ISBN " << "\n";
    std::cout << "2. Title " << "\n";
    std::cout << "3. Author " << "\n";
    std::cout << "4. Year " << "\n";
    std::cout << "5. Genre " << "\n";
    std::cout << "6. Rating " << "\n";
    std::cout << "7. Cancel and go back " << "\n";
    std::cout << "Enter choice: ";

    std::cin >> fieldChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    switch (fieldChoice) {

        // Edit Isbn
        case 1: {
            std::string newIsbn = "";

            std::cout << "Enter a new ISBN: " << "\n";
            std::cin >> newIsbn;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            Book updatedBook = it->second;
            updatedBook.setIsbn(newIsbn);

            this->bookCollection.erase(it);
            this->bookCollection.emplace(newIsbn, updatedBook);
            
            std::cout << "ISBN updated." << "\n";
            break;
        }

        // Edit Title
        case 2: {
            std::string newTitle = "";

            std::cout << "Enter a new Title:" << "\n";
            std::getline(std::cin, newTitle);
            it->second.setTitle(newTitle);
            std::cout << "Title updated." << "\n";
            break;
        }

        // Edit Author
        case 3: {
            std::string newAuthor = "";

            std::cout << "Enter a new Author:" << "\n";
            std::getline(std::cin, newAuthor);
            it->second.setAuthor(newAuthor);
            std::cout << "Author updated." << "\n";
            break;
        }

        // Edit Year
        case 4: {
            int newYear = 0;

            std::cout << "Enter a new Year:" << "\n";
            std::cin >> newYear;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            it->second.setYear(newYear);
            std::cout << "Year updated." << "\n";
            break;
        }

        // Edit Genre
        case 5: {
            std::string newGenre = "";

            std::cout << "Enter a new Genre:" << "\n";
            std::getline(std::cin, newGenre);
            it->second.setGenre(newGenre);
            std::cout << "Genre updated." << "\n";
            break;
        }

        // Edit Rating
        case 6: {
            int newRating = 0;

            std::cout << "Enter a new Rating:" << "\n";
            std::cin >> newRating;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            it->second.setRating(newRating);
            std::cout << "Rating updated." << "\n";
            break;
        }

        // Exits
        case 7:
            std::cout << "Returning to the main menu." << "\n";
            break;

        default:
            std::cout << "Invalid input." << "\n";
            break;

    }
    

}



// Remove Book by Key (ISBN)
void Library::removeBook() {
    std::string targetKey = "";

    std::cout << "\nEnter the ISBN (key) of the book to remove:" << "\n";

    std::cin >> targetKey;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    auto it = std::find_if(this->bookCollection.begin(), this->bookCollection.end(),
        [&targetKey](const auto &entry) {
            return entry.first == targetKey;
        }
    );


    if (it != this->bookCollection.end()) {
        std::cout << "\nRemoving "<< it->second.getTitle() << " ISBN: " << it->first << "\n";
        this->bookCollection.erase(it);
        std::cout << "Book removed from the library." << "\n";

    } else {
        std::cout << "\nSorry, no book was found with key " << targetKey << "\n";
    }

}




void Library::stats() {
    
    std::string exitKey = "";


    // If the library is empty
    if (this->bookCollection.empty()) {
        std::cout << "\nThe library is currently empty. No stats available." << "\n";
        return;
    }


    // Total number of books
    const auto totalBooks = std::count_if(this->bookCollection.begin(),this->bookCollection.end(),
        [](const auto &) { return true; }
    );



    // Output Response
    std::cout << "\nBook Statistics" << "\n";
    std::cout << "=======================" << "\n \n";

    std::cout << "Total number of books: " << totalBooks << "\n \n";
    std::cout << "Enter any key to go back." << "\n";
    std::cin >> exitKey;


}





