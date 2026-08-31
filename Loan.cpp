
#include "Loan.h"

Loan::Loan() {
    bookId = 0;
    memberId = 0;
    active = false;
}

Loan::Loan(int bookId, int memberId, bool active) {
    this->bookId = bookId;
    this->memberId = memberId;
    this->active = active;
}

int Loan::getBookId() const {
    return bookId;
}

int Loan::getMemberId() const {
    return memberId;
}

bool Loan::isActive() const {
    return active;
}

void Loan::setActive(bool active) {
    this->active = active;
}
