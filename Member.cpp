
#include "Member.h"

Member::Member() {
    id = 0;
    name = "";
    email = "";
}

Member::Member(int id, string name, string email) {
    this->id = id;
    this->name = name;
    this->email = email;
}

int Member::getId() const {
    return id;
}

string Member::getName() const {
    return name;
}

string Member::getEmail() const {
    return email;
}

void Member::setName(string name) {
    this->name = name;
}

void Member::setEmail(string email) {
    this->email = email;
}
