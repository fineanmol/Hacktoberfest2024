package com.lti.bookstore.service;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import com.lti.bookstore.model.Book;

public class BookService {
 
	
	
	private List<Book> listOfBooks=new ArrayList<Book>();

public void addBook(Book book)
{
	listOfBooks.add(book);
}
public List<Book> books()
{
	return Collections.unmodifiableList(listOfBooks);
	
}


public Book getBookById(String bookId)

{
	for(Book book:listOfBooks)
	{
		if(bookId.equals(book.getBookId()))
		{
			return book;
		}
	}
	return null;

}
}
