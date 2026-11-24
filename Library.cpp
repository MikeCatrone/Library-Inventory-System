
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
// void Library::displayBooks() {

    
// }





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





