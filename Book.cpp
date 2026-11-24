
#include "Book.h"


// Default constructor
Book::Book(){

    this->isbn = "0";
    this->title = "No Title";
    this->author = "No Author";
    this->year = 0;
    this->genre = "No Genre";
    this->rating = 0;
}


// All constructor
Book::Book(std::string isbn, std::string title, std::string author, int year, std::string genre, int rating){
    this->isbn = isbn;
    this->title = title;
    this->author = author;
    this->year = year;
    this->genre = genre;
    this->rating = rating;

}


// Destructor
Book::~Book(){}



// Setters
void Book::setIsbn(std::string isbn){
    this->isbn = isbn;
}


void Book::setTitle(std::string title){
    this->title = title;
}


void Book::setAuthor(std::string author){
    this->author = author;
}


void Book::setYear(int year){
    this->year = year;
}


void Book::setGenre(std::string genre){
    this->genre = genre;
}


void Book::setRating(int rating){
    this->rating = rating;
}



// Getters

std::string Book::getIsbn() const {
    return this->isbn;
}


std::string Book::getTitle() const {
    return this->title;
}


std::string Book::getAuthor() const {
    return this->author;
}


int Book::getYear() const {
    return this->year;
}


std::string Book::getGenre() const{
    return this->genre;
}


int Book::getRating() const {
    return this->rating;
}



// Display
void Book::display() const{
    std::cout << "ISBN: " << this->isbn << "\n";
    std::cout << "Title: " << this->title << "\n";
    std::cout << "Author: " << this->author << "\n";
    std::cout << "Year: " << this->year << "\n";
    std::cout << "Genre: " << this->genre << "\n";
    std::cout << "Rating: " << this->rating << "\n";
    
}

