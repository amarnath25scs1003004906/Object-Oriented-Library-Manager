
#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool available;

public:
    Book();
    Book(int id, string title, string author, bool available = true);

    int getId() const;
    string getTitle() const;
    string getAuthor() const;
    bool isAvailable() const;

    void setTitle(string title);
    void setAuthor(string author);
    void setAvailable(bool available);
};

#endif
