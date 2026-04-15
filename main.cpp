#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    string title;
    string author;

    Book(string t, string a) {
        title = t;
        author = a;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        string title, author;
        cin.ignore();
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);

        books.push_back(Book(title, author));
        cout << "Book added successfully!\n";
    }

    void showBooks() {
        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }

        for (int i = 0; i < books.size(); i++) {
            cout << i + 1 << ". " << books[i].title 
                 << " by " << books[i].author << endl;
        }
    }

    void removeBook() {
        int index;
        cout << "Enter book number to remove: ";
        cin >> index;

        if (index > 0 && index <= books.size()) {
            books.erase(books.begin() + index - 1);
            cout << "Book removed.\n";
        } else {
            cout << "Invalid index.\n";
        }
    }
};

int main() {
    Library lib;
    int choice;

    while (true) {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Show Books\n";
        cout << "3. Remove Book\n";
        cout << "4. Exit\n";

        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            lib.addBook();
        } else if (choice == 2) {
            lib.showBooks();
        } else if (choice == 3) {
            lib.removeBook();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}