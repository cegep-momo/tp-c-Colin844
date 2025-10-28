#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using namespace std;

class User {
private:
    static int nextId; // Compteur pour générer des IDs
    string name;
    string userId;
    vector<string> borrowedBooks; // Store ISBNs of borrowed books

public:
    // Constructors
    User();
    User(const string& name, const string& userId);
    User(const string& name); // Constructeur avec génération d'un Id
    
    // Getters
    string getName() const;
    string getUserId() const;
    vector<string> getBorrowedBooks() const;
    static int getNextId(); // Obtenir le prochain ID disponible
    
    // Setters
    void setName(const string& name);
    void setUserId(const string& userId);
    static void setNextId(int id); // Initialiser le compteur d'ID
    
    // Methods
    void borrowBook(const string& isbn);
    void returnBook(const string& isbn);
    bool hasBorrowedBook(const string& isbn) const;
    int getNumberOfBorrowedBooks() const;
    string toString() const;
    string toFileFormat() const;
    void fromFileFormat(const string& line);
};

#endif
