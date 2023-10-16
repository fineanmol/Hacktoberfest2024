import datetime
import os

class Library:
    def __init__(self,listofBooks):
        self.books=listofBooks

    def displayAvailableBooks(self):
        print("Books that are available in the library are:")
        for book in self.books:
            print("\t" +book)
    def BorrowBook(self,Bookname):
        if Bookname in self.books:
            print(f"You have been issued {Bookname}. Please handle it carefully and keep it safe. Return this book within 30 days.")
            self.books.remove(Bookname)
            return True
        else:
            print("Sorry, this book is either not available in the library or has already been issued to someone else. Please wait till the book has been returned. ")
            return False


    def returnBook(self,Bookname):
        self.books.append(Bookname)
        print("Thanks for returning this book! Have a great day ahead!")


class Student: 
        
    def requestBook(self):
        self.book = input("Enter the name of the book you want to borrow:")
        return self.book
    
    def returnBook(self):
        self.book = input("Enter the name of the book you want to return:")
        return self.book
    


if __name__=="__main__":
    CentraLibrary = Library(["DSA","Automata","Discrete mathematics","Computer architecture"])
    #CentraLibrary.displayAvailableBooks()
    student= Student()

    while(True):
        welcomemsg='''\n Welcome to the Central Library! 
        Please choose an option:
        1. List of all the available books
        2. Request a Book
        3. Add/Return a book
        4. Exit the Library'''

        print(welcomemsg)

        a=int(input('Enter your choice:'))

        if a==1:
            CentraLibrary.displayAvailableBooks()
        elif a==2:
            CentraLibrary.BorrowBook(student.requestBook())
        elif a==3:
            CentraLibrary.returnBook(student.returnBook())
        elif a==4:
            print("Thanks for visiting the Central Library! Have a great day ahead!")
            exit()
        else:
            print("Invalid choice!")
            
