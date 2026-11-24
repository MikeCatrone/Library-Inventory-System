

#include <iostream>

#ifndef BOOK_H
    #define BOOK_H


    class Book {

        private:

            std::string isbn;
            std::string title;
            std::string author;
            int year;
            std::string genre;
            int rating;

        public:

        
            // Default constructor
            Book();

            // All constructor
            Book(std::string, std::string, std::string, int, std::string, int);


            // Destructor
            ~Book();


            void setIsbn(std::string);
            void setTitle(std::string);
            void setAuthor(std::string);
            void setYear(int);
            void setGenre(std::string);
            void setRating(int);


            std::string getIsbn() const ;
            std::string getTitle() const;
            std::string getAuthor() const ;
            int getYear() const;
            std::string getGenre() const;
            int getRating() const;

            void display()const;

    };


#endif