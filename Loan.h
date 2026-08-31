
#ifndef LOAN_H
#define LOAN_H

class Loan {
private:
    int bookId;
    int memberId;
    bool active;

public:
    Loan();
    Loan(int bookId, int memberId, bool active = true);

    int getBookId() const;
    int getMemberId() const;
    bool isActive() const;

    void setActive(bool active);
};

#endif
