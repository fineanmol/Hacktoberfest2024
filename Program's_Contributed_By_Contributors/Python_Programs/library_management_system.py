# This program simulates a library where users can borrow and return books.
# It includes features like tracking available books, borrowing books, 
# and displaying library inventory.

class Library:
    """Base class for a Library"""
    
    def __init__(self, name):
        self.name = name
        self.books = []

    # Method to add books to the library
    def add_book(self, book):
        self.books.append(book)
        print(f'Book "{book.title}" added to the library.')

    # Method to display all available books
    def display_books(self):
        if len(self.books) > 0:
            print("\nAvailable books in the library:")
            for book in self.books:
                print(f'- {book.title} by {book.author}')
        else:
            print("\nNo books available in the library.")

    # Method to find a book in the library by title
    def find_book(self, title):
        for book in self.books:
            if book.title.lower() == title.lower():
                return book
        return None

class Book:
    """ Class for a Book, representing individual books"""
    
    def __init__(self, title, author):
        self.title = title
        self.author = author
        self.is_borrowed = False

    # Method to borrow a book
    def borrow(self):
        if not self.is_borrowed:
            self.is_borrowed = True
            print(f'You have borrowed "{self.title}".')
        else:
            print(f'Sorry, "{self.title}" is currently borrowed.')

    # Method to return a borrowed book
    def return_book(self):
        if self.is_borrowed:
            self.is_borrowed = False
            print(f'Thank you for returning "{self.title}".')
        else:
            print(f'"{self.title}" was not borrowed.')

class User:
    """ Class for a User, who can borrow and return books """

    def __init__(self, name, library):
        self.name = name
        self.library = library

    # Method for user to borrow a book
    def borrow_book(self, book_title):
        book = self.library.find_book(book_title)
        if book:
            book.borrow()
        else:
            print(f'Sorry, the book "{book_title}" is not available in the library.')

    # Method for user to return a book
    def return_book(self, book_title):
        book = self.library.find_book(book_title)
        if book:
            book.return_book()
        else:
            print(f'The book "{book_title}" does not belong to this library.')


def main():
    """ Example usage of the Library Management System """
    
    # Create a Library object
    city_library = Library("City Library")

    # Create some books
    book1 = Book("The Great Gatsby", "F. Scott Fitzgerald")
    book2 = Book("1984", "George Orwell")
    book3 = Book("To Kill a Mockingbird", "Harper Lee")

    # Add books to the library
    city_library.add_book(book1)
    city_library.add_book(book2)
    city_library.add_book(book3)

    # Display available books
    city_library.display_books()

    # Create a User
    user1 = User("Alice", city_library)

    # User borrows a book
    user1.borrow_book("1984")

    # Try to borrow the same book again
    user1.borrow_book("1984")

    # Display available books after borrowing
    city_library.display_books()

    # User returns a book
    user1.return_book("1984")

    # Display available books after returning
    city_library.display_books()

if __name__ == "__main__":
    main()
