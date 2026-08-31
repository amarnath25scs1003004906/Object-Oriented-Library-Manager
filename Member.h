
#ifndef MEMBER_H
#define MEMBER_H

#include <string>
using namespace std;

class Member {
private:
    int id;
    string name;
    string email;

public:
    Member();
    Member(int id, string name, string email);

    int getId() const;
    string getName() const;
    string getEmail() const;

    void setName(string name);
    void setEmail(string email);
};

#endif
