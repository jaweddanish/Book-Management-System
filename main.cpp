class Book:
    def __init__(self, id, title, author, genre, published_year):
        self.id = id
        self.title = title
        self.author = author
        self.genre = genre
        self.published_year = published_year

    def get_id(self):
        return self.id

    def get_title(self):
        return self.title

    def get_author(self):
        return self.author

    def get_genre(self):
        return self.genre

    def get_published_year(self):
        return self.published_year

    def set_title(self, new_title):
        self.title = new_title

    def set_author(self, new_author):
        self.author = new_author

    def set_genre(self, new_genre):
        self.genre = new_genre

    def set_published_year(self, new_year):
        self.published_year = new_year

    def display(self):
        print(f"ID: {self.id}, Title: {self.title}, Author: {self.author}, "
              f"Genre: {self.genre}, Published Year: {self.published_year}")


class BookInventory:
    def __init__(self):
        self.books = []
        self.next_id = 1

    def add_book(self, title, author, genre, published_year):
        self.books.append(Book(self.next_id, title, author, genre, published_year))
        self.next_id += 1

    def update_book(self, id, title, author, genre, published_year):
        for book in self.books:
            if book.get_id() == id:
                book.set_title(title)
                book.set_author(author)
                book.set_genre(genre)
                book.set_published_year(published_year)
                return
        print(f"Book with ID {id} not found.")

    def delete_book(self, id):
        for book in self.books:
            if book.get_id() == id:
                self.books.remove(book)
                return
        print(f"Book with ID {id} not found.")

    def display_books(self):
        for book in self.books:
            book.display()

    def display_books_by_author(self, author):
        for book in self.books:
            if book.get_author() == author:
                book.display()

    def display_books_by_genre(self, genre):
        for book in self.books:
            if book.get_genre() == genre:
                book.display()

    def display_books_by_year(self, year):
        for book in self.books:
            if book.get_published_year() == year:
                book.display()


def main():
    inventory = BookInventory()

    inventory.add_book("The Great Gatsby", "F. Scott Fitzgerald", "Novel", 1925)
    inventory.add_book("To Kill a Mockingbird", "Harper Lee", "Novel", 1960)
    inventory.add_book("1984", "George Orwell", "Dystopian", 1949)

    print("All Books:")
    inventory.display_books()

    print("\nBooks by George Orwell:")
    inventory.display_books_by_author("George Orwell")

    print("\nBooks in Novel genre:")
    inventory.display_books_by_genre("Novel")

    print("\nBooks published in 1949:")
    inventory.display_books_by_year(1949)

    inventory.update_book(2, "To Kill a Mockingbird", "Harper Lee", "Classic", 1960)
    print("\nUpdated Book with ID 2:")
    inventory.display_books()

    inventory.delete_book(1)
    print("\nBooks after deleting book with ID 1:")
    inventory.display_books()


if __name__ == "__main__":
    main()
