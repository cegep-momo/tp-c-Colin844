#include <sstream>
#include <algorithm>
#include <iomanip>

#include "user.h"

using namespace std;

// Default constructor
User::User() : name(""), userId("") {}

// Parameterized constructor
User::User(const string& name, const string& userId) 
    : name(name), userId(userId) {}

// Constructeur avec génération d'ID
User::User(const string& name) : name(name) {
    // Génère un ID du type USR### (ex : USR001)
    stringstream ss;
    ss << setw(3) << setfill('0') << nextId++;
    userId = string("USR") + ss.str();
}

// Getters
string User::getName() const { return name; }
string User::getUserId() const { return userId; }
vector<string> User::getBorrowedBooks() const { return borrowedBooks; }

// Setters
void User::setName(const string& name) { this->name = name; }
void User::setUserId(const string& userId) { this->userId = userId; }

// Borrow a book
void User::borrowBook(const string& isbn) {
    if (!hasBorrowedBook(isbn)) {
        borrowedBooks.push_back(isbn);
    }
}

// Return a book
void User::returnBook(const string& isbn) {
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), isbn);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
    }
}

// Check if user has borrowed a specific book
bool User::hasBorrowedBook(const string& isbn) const {
    return find(borrowedBooks.begin(), borrowedBooks.end(), isbn) != borrowedBooks.end();
}

// Get number of borrowed books
int User::getNumberOfBorrowedBooks() const {
    return borrowedBooks.size();
}

// Display user information
string User::toString() const {
    string result = "Nom: " + name + "\nID: " + userId + 
                        "\nLivres empruntés : " + to_string(borrowedBooks.size());
    
    if (!borrowedBooks.empty()) {
        result += "\nISBNs: ";
        for (size_t i = 0; i < borrowedBooks.size(); ++i) {
            result += borrowedBooks[i];
            if (i < borrowedBooks.size() - 1) result += ", ";
        }
    }
    return result;
}

// Format for file storage
string User::toFileFormat() const {
    string result = name + "|" + userId + "|";
    for (size_t i = 0; i < borrowedBooks.size(); ++i) {
        result += borrowedBooks[i];
        if (i < borrowedBooks.size() - 1) result += ",";
    }
    return result;
}

// Parse from file format
void User::fromFileFormat(const string& line) {
    stringstream ss(line);
    string token;
    
    getline(ss, name, '|');
    getline(ss, userId, '|');
    
    string booksStr;
    getline(ss, booksStr, '|');
    
    borrowedBooks.clear();
    if (!booksStr.empty()) {
        stringstream booksSs(booksStr);
        string isbn;
        while (getline(booksSs, isbn, ',')) {
            borrowedBooks.push_back(isbn);
        }
    }

    // Mise à jour nextId pour éviter les doublons d'ID lors du chargement
    if (userId.rfind("USR", 0) == 0) {
        string num = userId.substr(3);
            int val = stoi(num);
            if (val >= nextId) nextId = val + 1;
    }
}

// Définition variable statique et méthodes d'accès
int User::nextId = 1;

int User::getNextId() { return nextId; }
void User::setNextId(int id) { nextId = id; }
