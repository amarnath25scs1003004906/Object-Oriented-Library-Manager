
#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"
#include "Member.h"
#include "Loan.h"

using namespace std;

class Library {
private:
    vector<Book> books;
    vector<Member> members;
    vector<Loan> loans;

    Book* findBook(int id);
    Member* findMember(int id);
    Loan* findLoan(int bookId);

public:
    void addBook();
    void addMember();

    void listBooks() const;
    void listMembers() const;

    void searchBook() const;
    void checkAvailability() const;

    void issueBook();
    void returnBook();

    void saveRecords() const;
    void loadRecords();
};

#endif
