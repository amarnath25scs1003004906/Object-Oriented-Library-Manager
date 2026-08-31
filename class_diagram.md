# Class Diagram

```text
+----------------------+
|        Book          |
+----------------------+
| - id: int            |
| - title: string      |
| - author: string     |
| - available: bool    |
+----------------------+
| + Book()             |
| + Book(...)          |
| + getId()            |
| + getTitle()         |
| + getAuthor()        |
| + isAvailable()      |
| + setTitle()         |
| + setAuthor()        |
| + setAvailable()     |
+----------------------+


+----------------------+
|       Member         |
+----------------------+
| - id: int            |
| - name: string       |
| - email: string      |
+----------------------+
| + Member()           |
| + Member(...)        |
| + getId()            |
| + getName()          |
| + getEmail()         |
| + setName()          |
| + setEmail()         |
+----------------------+


+----------------------+
|        Loan          |
+----------------------+
| - bookId: int        |
| - memberId: int      |
| - active: bool       |
+----------------------+
| + Loan()             |
| + Loan(...)          |
| + getBookId()        |
| + getMemberId()      |
| + isActive()         |
| + setActive()        |
+----------------------+


+--------------------------------+
|            Library             |
+--------------------------------+
| - books: vector<Book>          |
| - members: vector<Member>      |
| - loans: vector<Loan>          |
+--------------------------------+
| + addBook()                    |
| + addMember()                  |
| + listBooks()                  |
| + listMembers()                |
| + searchBook()                 |
| + checkAvailability()          |
| + issueBook()                  |
| + returnBook()                 |
| + saveRecords()                |
| + loadRecords()                |
+--------------------------------+

Relationships:

Library manages collections of Book, Member, and Loan objects.

Loan connects a Book with a Member.

Book availability changes when it is issued or returned.
