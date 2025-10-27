// book.cpp 
#include <iostream>
#include <sstream>
#include "book.h"

// Constructeur par défaut
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerName("") {}

// Constructeur avec paramètres
Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerName("") {}

// Getters
string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getISBN() const {
    return isbn;
}

bool Book::getAvailability() const {
    return isAvailable;
}

string Book::getBorrowerName() const {
    return borrowerName;
}

// Setters
void Book::setTitle(const string& title) {
    this->title = title;
}

void Book::setAuthor(const string& author) {
    this->author = author;
}

void Book::setISBN(const string& isbn) {
    this->isbn = isbn;
}

void Book::setAvailability(bool available) {
    isAvailable = available;
}

void Book::setBorrowerName(const string& name) {
    borrowerName = name;
}

// Méthodes
/**
 * TODO: Implémenter les méthodes suivantes
 */
void Book::checkOut(const string& borrower) {
    if (isAvailable) {
        isAvailable = false;
        borrowerName = borrower;
    } else {
        cout << "Book is already checked out." << endl;
    }
}

void Book::returnBook() {
    if (!isAvailable) {
        isAvailable = true;
        borrowerName = "";
    } else {
        cout << "Book is not checked out." << endl;
    }
}

string Book::toString() const {
    return "Title: " + title + "| Author: " + author + "| ISBN: " + isbn + "| Available: " + (isAvailable ? "Yes" : "No") + (isAvailable ? "" : "| Borrower: " + borrowerName);
}

string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerName;
}

void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string token;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, token, '|');
    isAvailable = (token == "1");
    getline(ss, borrowerName, '|');
}
