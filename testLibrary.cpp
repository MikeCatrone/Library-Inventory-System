
#include <iostream>

#include "Book.h"
#include "Library.h"




// Show main menu
void showMainMenu();



int main() {


    // Main Library Map
    Library library;

    int choice = 0;


    
    // 5 books for testing
    Book book1("171717", "Jurassic Park", "Michael Crichton", 1990, "Drama", 7);
    Book book2("12345", "To Kill a Mockingbird", "Harper Lee", 1960, "Drama", 8);
    Book book3("5451199", "The Hobbit", "J.R Tolkien", 1956, "Fantasy", 10);
    Book book4("191919", "A Game of Thrones", "George R. Martin", 1996, "Fantasy", 10);
    Book book5("474747", "Harry Potter and the Sorcerers Stone", "J.K Rowling", 1997, "Fantasy", 8);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);
    library.addBook(book5);

   
  
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    while (choice != 7)
    {

        showMainMenu();

        std::cin >> choice;

        // Add a Book
        if(choice == 1) {

        
            // Temp Variables
            std::string tempIsbn = "";
            std::string tempTitle = "";
            std::string tempAuthor = "";
            int tempYear = 0;
            std::string tempGenre = "";
            int tempRating = 0;
            
            
            // Gathering User info
            std::cout << "Enter an ISBN:\n";
            std::cin >> tempIsbn;

            // Clear the leftover newline '\n' from std::cin >> before calling std::getline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter a Title:\n";
            std::getline(std::cin, tempTitle);

            std::cout << "Enter an Author:\n";
            std::getline(std::cin, tempAuthor);

            std::cout << "Enter a Year:\n";
            std::cin >> tempYear;

            // Clear the leftover newline again before reading Genre with std::getline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter a Genre:\n";
            std::getline(std::cin, tempGenre);

            std::cout << "Enter a Rating:\n";
            std::cin >> tempRating;


            // Create a book bases on the user input
            Book book6(tempIsbn, tempTitle, tempAuthor, tempYear, tempGenre, tempRating);


            // add the book to the map container
            library.addBook(book6);


        }


        // Display all books
        if(choice == 2) {
            library.displayBooks();
        }


        // Search for a book
        if(choice == 3) {
            library.searchBook();
        }


        // Edit a book
        if(choice == 4) {
            library.editBook();

        }


        // Remove a book
        // if(choice == 5) {
        //     library.removeBook();
            
        // }

        // Remove a book
        // if(choice == 6) {
        //     library.stats();
            
        // }

        
    }


    return 0;
}



// Shows main menu
void showMainMenu(){

    std::cout << "\n Library - C++" << "\n";
    std::cout << "================================" << "\n \n";
    std::cout << "Select an option:" << "\n \n";
    std::cout << "1. Add a Book" << "\n";
    std::cout << "2. Show all Books" << "\n";
    std::cout << "3. Search a Book" << "\n";
    std::cout << "4. Update a Book" << "\n";
    std::cout << "5. Remove a Book" << "\n";
    std::cout << "6. Book Stats" << "\n";
    std::cout << "7. Exit" << "\n";
    
}

