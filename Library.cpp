
#include "Library.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <iomanip>

using namespace std;

// Find a book by ID
Book* Library::findBook(int id) {
    for (Book& book : books) {
        if (book.getId() == id) {
            return &book;
        }
    }

    return nullptr;
}

// Find a member by ID
Member* Library::findMember(int id) {
    for (Member& member : members) {
        if (member.getId() == id) {
            return &member;
        }
    }

    return nullptr;
}

// Find a loan using book ID
Loan* Library::findLoan(int bookId) {
    for (Loan& loan : loans) {
        if (loan.getBookId() == bookId && loan.isActive()) {
            return &loan;
        }
    }

    return nullptr;
}

// Add a book
void Library::addBook() {
    int id;
    string title;
    string author;

    cout << "\n===== ADD BOOK =====\n";

    cout << "Enter book ID: ";

    while (!(cin >> id) || id <= 0) {
        cout << "Invalid ID. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (findBook(id) != nullptr) {
        cout << "A book with this ID already exists.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter title: ";
    getline(cin, title);

    while (title.empty()) {
        cout << "Title cannot be empty. Enter again: ";
        getline(cin, title);
    }

    cout << "Enter author: ";
    getline(cin, author);

    while (author.empty()) {
        cout << "Author cannot be empty. Enter again: ";
        getline(cin, author);
    }

    books.push_back(Book(id, title, author));

    cout << "Book added successfully!\n";
}

// Add a member
void Library::addMember() {
    int id;
    string name;
    string email;

    cout << "\n===== ADD MEMBER =====\n";

    cout << "Enter member ID: ";

    while (!(cin >> id) || id <= 0) {
        cout << "Invalid ID. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (findMember(id) != nullptr) {
        cout << "A member with this ID already exists.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter name: ";
    getline(cin, name);

    while (name.empty()) {
        cout << "Name cannot be empty. Enter again: ";
        getline(cin, name);
    }

    cout << "Enter email: ";
    getline(cin, email);

    while (email.empty()) {
        cout << "Email cannot be empty. Enter again: ";
        getline(cin, email);
    }

    members.push_back(Member(id, name, email));

    cout << "Member added successfully!\n";
}

// List all books
void Library::listBooks() const {
    cout << "\n===== BOOK LIST =====\n";

    if (books.empty()) {
        cout << "No books available.\n";
        return;
    }

    cout << left
         << setw(8) << "ID"
         << setw(25) << "Title"
         << setw(25) << "Author"
         << "Status\n";

    cout << string(70, '-') << endl;

    for (const Book& book : books) {
        cout << left
             << setw(8) << book.getId()
             << setw(25) << book.getTitle()
             << setw(25) << book.getAuthor()
             << (book.isAvailable() ? "Available" : "Issued")
             << endl;
    }
}

// List all members
void Library::listMembers() const {
    cout << "\n===== MEMBER LIST =====\n";

    if (members.empty()) {
        cout << "No members registered.\n";
        return;
    }

    cout << left
         << setw(8) << "ID"
         << setw(25) << "Name"
         << "Email\n";

    cout << string(60, '-') << endl;

    for (const Member& member : members) {
        cout << left
             << setw(8) << member.getId()
             << setw(25) << member.getName()
             << member.getEmail()
             << endl;
    }
}

// Search for a book
void Library::searchBook() const {
    int id;

    cout << "\n===== SEARCH BOOK =====\n";
    cout << "Enter book ID: ";

    while (!(cin >> id)) {
        cout << "Invalid input. Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (const Book& book : books) {
        if (book.getId() == id) {
            cout << "\nBook found!\n";
            cout << "ID: " << book.getId() << endl;
            cout << "Title: " << book.getTitle() << endl;
            cout << "Author: " << book.getAuthor() << endl;
            cout << "Status: "
                 << (book.isAvailable() ? "Available" : "Issued")
                 << endl;
            return;
        }
    }

    cout << "Book not found.\n";
}

// Check availability
void Library::checkAvailability() const {
    int id;

    cout << "\n===== CHECK AVAILABILITY =====\n";
    cout << "Enter book ID: ";

    while (!(cin >> id)) {
        cout << "Invalid input. Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (const Book& book : books) {
        if (book.getId() == id) {
            cout << "Book: " << book.getTitle() << endl;

            if (book.isAvailable()) {
                cout << "Status: AVAILABLE\n";
            } else {
                cout << "Status: ISSUED\n";
            }

            return;
        }
    }

    cout << "Book not found.\n";
}

// Issue a book
void Library::issueBook() {
    int bookId;
    int memberId;

    cout << "\n===== ISSUE BOOK =====\n";

    cout << "Enter book ID: ";

    while (!(cin >> bookId)) {
        cout << "Invalid book ID. Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Book* book = findBook(bookId);

    if (book == nullptr) {
        cout << "Book not found.\n";
        return;
    }

    if (!book->isAvailable()) {
        cout << "Book is already issued.\n";
        return;
    }

    cout << "Enter member ID: ";

    while (!(cin >> memberId)) {
        cout << "Invalid member ID. Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Member* member = findMember(memberId);

    if (member == nullptr) {
        cout << "Member not found.\n";
        return;
    }

    book->setAvailable(false);

    loans.push_back(Loan(bookId, memberId, true));

    cout << "Book issued successfully to "
         << member->getName() << ".\n";
}

// Return a book
void Library::returnBook() {
    int bookId;

    cout << "\n===== RETURN BOOK =====\n";

    cout << "Enter book ID: ";

    while (!(cin >> bookId)) {
        cout << "Invalid book ID. Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Book* book = findBook(bookId);

    if (book == nullptr) {
        cout << "Book not found.\n";
        return;
    }

    if (book->isAvailable()) {
        cout << "This book is not currently issued.\n";
        return;
    }

    Loan* loan = findLoan(bookId);

    if (loan != nullptr) {
        loan->setActive(false);
    }

    book->setAvailable(true);

    cout << "Book returned successfully.\n";
}

// Save records to files
void Library::saveRecords() const {

    ofstream bookFile("books.txt");
    ofstream memberFile("members.txt");
    ofstream loanFile("loans.txt");

    if (!bookFile || !memberFile || !loanFile) {
        cout << "Error: Unable to save records.\n";
        return;
    }

    for (const Book& book : books) {
        bookFile << book.getId() << "|"
                 << book.getTitle() << "|"
                 << book.getAuthor() << "|"
                 << book.isAvailable() << "\n";
    }

    for (const Member& member : members) {
        memberFile << member.getId() << "|"
                   << member.getName() << "|"
                   << member.getEmail() << "\n";
    }

    for (const Loan& loan : loans) {
        loanFile << loan.getBookId() << "|"
                 << loan.getMemberId() << "|"
                 << loan.isActive() << "\n";
    }

    cout << "Records saved successfully.\n";
}

// Load records from files
void Library::loadRecords() {

    ifstream bookFile("books.txt");
    ifstream memberFile("members.txt");
    ifstream loanFile("loans.txt");

    books.clear();
    members.clear();
    loans.clear();

    string line;

    // Load books
    while (getline(bookFile, line)) {
        if (line.empty())
            continue;

        stringstream ss(line);

        string idStr;
        string title;
        string author;
        string availableStr;

        getline(ss, idStr, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, availableStr, '|');

        try {
            int id = stoi(idStr);
            bool available = stoi(availableStr);

            books.push_back(
                Book(id, title, author, available)
            );
        }
        catch (...) {
            cout << "Warning: Invalid book record skipped.\n";
        }
    }

    // Load members
    while (getline(memberFile, line)) {
        if (line.empty())
            continue;

        stringstream ss(line);

        string idStr;
        string name;
        string email;

        getline(ss, idStr, '|');
        getline(ss, name, '|');
        getline(ss, email, '|');

        try {
            int id = stoi(idStr);

            members.push_back(
                Member(id, name, email)
            );
        }
        catch (...) {
            cout << "Warning: Invalid member record skipped.\n";
        }
    }

    // Load loans
    while (getline(loanFile, line)) {
        if (line.empty())
            continue;

        stringstream ss(line);

        string bookIdStr;
        string memberIdStr;
        string activeStr;

        getline(ss, bookIdStr, '|');
        getline(ss, memberIdStr, '|');
        getline(ss, activeStr, '|');

        try {
            int bookId = stoi(bookIdStr);
            int memberId = stoi(memberIdStr);
            bool active = stoi(activeStr);

            loans.push_back(
                Loan(bookId, memberId, active)
            );
        }
        catch (...) {
            cout << "Warning: Invalid loan record skipped.\n";
        }
    }

    cout << "Records loaded successfully.\n";
}
