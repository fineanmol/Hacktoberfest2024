package com.lti.junit5;

import org.junit.*;
import static org.junit.jupiter.api.Assertions.*;

import java.util.List;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import com.lti.bookstore.model.Book;
import com.lti.bookstore.service.BookService;


class FirstJUnit5Test {
	BookService bookService = new BookService();
	
	
	



	
	
	
	
	
	
	@Test // indicated or marks the mesthod as test method
	void test() {
		 System.out.print("hello,All");
		//assertEquals(2,5);

	}

	
	@Test
	void assertTrueMethod() {

		// List<Book> listOfBooks=bookService.books();

		Book javaBook = new Book("1", "Java", "Simant");
		bookService.addBook(javaBook);
		List<Book> listOfBooks = bookService.books();
		
		// assertTrue(listOfBooks.isEmpty(), "List of book is not empty");
		// assertTrue(listOfBooks.isEmpty(), ()->"List of book is not empty");
		// assertTrue(()->listOfBooks.isEmpty());
		//assertTrue(() -> listOfBooks.isEmpty(), "List is not empty");
		//assertFalse(() -> listOfBooks.isEmpty(), "List is not empty");
       
	}
	
	
	@Test
	
	void assertNullMethod(){
		Book javaBook = new Book("1", "Java", "Si");
		Book pyBook = new Book("2", "python", "mant");
		Book juBook = new Book("3", "jupiter", "ant");
		Book rBook = new Book("4", "ruby", "Sim");
		
		
		bookService.addBook(javaBook);
		bookService.addBook(pyBook);
		bookService.addBook(juBook);
		bookService.addBook(rBook);
		
		
		//Book book=bookService.getBookById("3");
		//Book book=bookService.getBookById("8");
		
		Book book=bookService.getBookById("2");
		//assertNull(book);
		//assertNull(book,"Book Found");
		//assertNull(book,()->"Book is not Null");
		assertNotNull(book,()->"is Null");
		
	}
	
	@Test
	void assertEqualsMethod()
	{
		Book javaBook = new Book("1", "Java", "Si");
		Book pyBook = new Book("2", "python", "mant");
		Book juBook = new Book("3", "jupiter", "ant");
		Book rBook = new Book("4", "ruby", "Sim");
		
		
		bookService.addBook(javaBook);
		bookService.addBook(pyBook);
		bookService.addBook(juBook);
		bookService.addBook(rBook);
		Book book=bookService.getBookById("1");
	    //assertEquals("1",book.getBookId());
	    assertEquals("Java",book.getTitle());
		
		
		
	}
}
