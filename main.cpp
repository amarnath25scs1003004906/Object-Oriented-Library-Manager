
#include <iostream>
#include <limits>
#include "Library.h"

using namespace std;

int main() {

    Library library;

    // Load saved records when program starts
    library.loadRecords();

    int choice;

    cout << "\n========================================\n";
    cout << "       OBJECT-ORIENTED LIBRARY\n";
    cout << "          MANAGEMENT SYSTEM\n";
    cout << "========================================\n";

    while (true) {

        cout << "\n============= MENU =============\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. List Books\n";
        cout << "4. List Members\n";
        cout << "5. Search Book\n";
        cout << "6. Check Availability\n";
        cout << "7. Issue Book\n";
        cout << "8. Return Book\n";
        cout << "9. Save Records\n";
        cout << "10. Exit\n";
        cout << "================================\n";

        cout << "Enter your choice: ";

        if (!(cin >> choice)) {

            cout << "Invalid input! Please enter a number.\n";

            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            continue;
        }

        switch (choice) {

            case 1:
                library.addBook();
                break;

            case 2:
                library.addMember();
                break;

            case 3:
                library.listBooks();
                break;

            case 4:
                library.listMembers();
                break;

            case 5:
                library.searchBook();
                break;

            case 6:
                library.checkAvailability();
                break;

            case 7:
                library.issueBook();
                break;

            case 8:
                library.returnBook();
                break;

            case 9:
                library.saveRecords();
                break;

            case 10:
                library.saveRecords();

                cout << "\nThank you for using "
                     << "Library Management System!\n";

                return 0;

            default:
                cout << "Invalid choice! "
                     << "Please select 1 to 10.\n";
        }
    }

    return 0;
}
