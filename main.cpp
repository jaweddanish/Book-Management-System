#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    string genre;
    int publishedYear;

public:
    Book(int id, string title, string author, string genre, int publishedYear) 
        : id(id), title(title), author(author), genre(genre), publishedYear(publishedYear) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getGenre() const { return genre; }
    int getPublishedYear() const { return publishedYear; }

    void setTitle(const string& newTitle) { title = newTitle; }
    void setAuthor(const string& newAuthor) { author = newAuthor; }
    void setGenre(const string& newGenre) { genre = newGenre; }
    void setPublishedYear(int newYear) { publishedYear = newYear; }

    void display() const {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author 
             << ", Genre: " << genre << ", Published Year: " << publishedYear << endl;
    }
};

class BookInventory {
private:
    vector<Book> books;
    int nextId;

public:
    BookInventory() : nextId(1) {}

    void addBook(const string& title, const string& author, const string& genre, int publishedYear) {
        books.push_back(Book(nextId++, title, author, genre, publishedYear));
    }

    void updateBook(int id, const string& title, const string& author, const string& genre, int publishedYear) {
        for (Book& book : books) {
            if (book.getId() == id) {
                book.setTitle(title);
                book.setAuthor(author);
                book.setGenre(genre);
                book.setPublishedYear(publishedYear);
                return;
            }
        }
        cout << "Book with ID " << id << " not found." << endl;
    }

    void deleteBook(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getId() == id) {
                books.erase(it);
                return;
            }
        }
        cout << "Book with ID " << id << " not found." << endl;
    }

    void displayBooks() const {
        for (const Book& book : books) {
            book.display();
        }
    }

    void displayBooksByAuthor(const string& author) const {
        for (const Book& book : books) {
            if (book.getAuthor() == author) {
                book.display();
            }
        }
    }

    void displayBooksByGenre(const string& genre) const {
        for (const Book& book : books) {
            if (book.getGenre() == genre) {
                book.display();
            }
        }
    }

    void displayBooksByYear(int year) const {
        for (const Book& book : books) {
            if (book.getPublishedYear() == year) {
                book.display();
            }
        }
    }
};

int main() {
    BookInventory inventory;
    
    inventory.addBook("The Great Gatsby", "F. Scott Fitzgerald", "Novel", 1925);
    inventory.addBook("To Kill a Mockingbird", "Harper Lee", "Novel", 1960);
    inventory.addBook("1984", "George Orwell", "Dystopian", 1949);

    cout << "All Books:" << endl;
    inventory.displayBooks();

    cout << "\nBooks by George Orwell:" << endl;
    inventory.displayBooksByAuthor("George Orwell");

    cout << "\nBooks in Novel genre:" << endl;
    inventory.displayBooksByGenre("Novel");

    cout << "\nBooks published in 1949:" << endl;
    inventory.displayBooksByYear(1949);

    inventory.updateBook(2, "To Kill a Mockingbird", "Harper Lee", "Classic", 1960);
    cout << "\nUpdated Book with ID 2:" << endl;
    inventory.displayBooks();

    inventory.deleteBook(1);
    cout << "\nBooks after deleting book with ID 1:" << endl;
    inventory.displayBooks();

    return 0;
}
