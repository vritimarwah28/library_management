#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// Book class to store details of each book
struct Book {
    string title;
    string author;
    string isbn;
    int publicationYear;

    // Constructor to set values when a book is created
    Book(string t, string a, string i, int p)
        {
            title=t;
            author=a;
            isbn=i;
            publicationYear=p;
        }
};

// Library class to store and manage books
class Library {
private:
    vector<Book> books;  // List of books in the library

public:
    // Add a new book to the library
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Search for books by title (case-sensitive)
    void searchByTitle(const string& title) {
        bool found = false;
        for (const auto& book : books) {
            if (book.title.find(title) != string::npos) {  // Title contains search text
                displayBook(book);
                found = true;
            }
        }
        if (!found) {
            cout << "No books found with title: " << title << endl;
        }
    }

    // Search for books by author (case-sensitive)
    void searchByAuthor(const string& author) {
        bool found = false;
        for (const auto& book : books) {
            if (book.author.find(author) !=string::npos) {  // Author contains search text
                displayBook(book);
                found = true;
            }
        }
        if (!found) {
            cout << "No books found by author: " << author << endl;
        }
    }

    // Search for books by ISBN (exact match)
    void searchByISBN(const string& isbn) {
        bool found = false;
        for (const auto& book : books) {
            if (book.isbn == isbn) {
                displayBook(book);
                found = true;
            }
        }
        if (!found) {
            cout << "No books found with ISBN: " << isbn <<endl;
        }
    }

    // Advanced search (case-insensitive for title or author)
    void advancedSearch(const string& searchQuery) {
        bool found = false;
        for (const auto& book : books) {
            // Case-insensitive search for title or author
            if (caseInsensitiveSearch(book.title, searchQuery) || 
                caseInsensitiveSearch(book.author, searchQuery)) {
                displayBook(book);
                found = true;
            }
        }
        if (!found) {
            cout << "No books found matching the query: " << searchQuery << endl;
        }
    }

    // Display details of a book
    void displayBook(const Book& book) const {
        cout << "Title: " << book.title << "\n"<< "Author: " << book.author << "\n"
        << "ISBN: " << book.isbn << "\n"<< "Publication Year: " << book.publicationYear << "\n"
        << "-------------------------\n";
    }

private:
    // Helper function to make search case-insensitive
    bool caseInsensitiveSearch(const string& str, const string& query) const {
        string strLower = str;
        string queryLower = query;
        transform(strLower.begin(), strLower.end(), strLower.begin(), ::tolower);
        transform(queryLower.begin(), queryLower.end(), queryLower.begin(), ::tolower);
        return strLower.find(queryLower) != string::npos;
    }
};

int main() {
    Library library;

    // Add some books to the library
    library.addBook(Book("One Indian Girl", "Chetan Bhagat", "9728121939288", 2016));
    library.addBook(Book("When the Heavens smiled", "Ritesh Arora", "9780061120084", 2015));
    library.addBook(Book("1984", "George Orwell", "9780451524935", 1949));
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", 1925));
    library.addBook(Book("Moby Dick", "Herman Melville", "9781503280786", 1851));

    int choice;
    string searchQuery;

    do {
        // Display the menu to the user
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Search by Title\n";
        std::cout << "2. Search by Author\n";
        std::cout << "3. Search by ISBN\n";
        std::cout << "4. Advanced Search (case-insensitive)\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter title to search for: ";
                cin.ignore();  // Ignore leftover newline
                getline(std::cin, searchQuery);
                library.searchByTitle(searchQuery);
                break;

            case 2:
                cout << "Enter author to search for: ";
                cin.ignore();  // Ignore leftover newline
                getline(cin, searchQuery);
                library.searchByAuthor(searchQuery);
                break;

            case 3:
                cout << "Enter ISBN to search for: ";
                cin >> searchQuery;
                library.searchByISBN(searchQuery);
                break;

            case 4:
                cout << "Enter search query (title or author): ";
                cin.ignore();  // Ignore leftover newline
                getline(cin, searchQuery);
                library.advancedSearch(searchQuery);
                break;

            case 5:
                cout << "Exiting the system...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
 