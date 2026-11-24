
#include <iostream>
#include "Book.h"
#include <map>



#ifndef LIBRARY_H
    #define LIBRARY_H


    class Library {

        private:

            std::map<std::string, Book> bookCollection;
            

        public:

        
            // Default constructor
            Library();

    
            // Destructor
            ~Library();


            // Add Book
            void addBook(Book);


            // GetMap
            std::map<std::string, Book> getMap() const;


            // Show all books
            // void displayBooks() const;


            // Search all books
            // void searchBook();


            // Edit a book
            // void editBook();

            // Remove a book
            // void removeBook();


            // Average Stats
            // void stats();
            
            
    };


#endif