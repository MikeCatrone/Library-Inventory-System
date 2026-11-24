
#include "Library.h"
#include "Book.h"

#include <algorithm>
#include <iostream>
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





// Search Book
// void Library::searchBook() {

    
// }




// Edit a Book
// void Library::editBook() {
   
 
// }



// Remove Book by Key (ISBN)
// void Library::removeBook() {
    

// }




// void Library::stats() {
    
// }





