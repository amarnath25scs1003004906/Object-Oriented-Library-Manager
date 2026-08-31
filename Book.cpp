
#include "Book.h"

Book::Book() {
    id = 0;
    title = "";
    author = "";
    available = true;
}

Book::Book(int id, string title, string author, bool available) {
    this->id = id;
    this->title = title;
    this->author = author;
    this->available = available;
}

int Book::getId() const {
    return id;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

bool Book::isAvailable() const {
    return available;
}

void Book::setTitle(string title) {
    this->title = title;
}

void Book::setAuthor(string author) {
    this->author = author;
}

void Book::setAvailable(bool available) {
    this->available = available;
}
