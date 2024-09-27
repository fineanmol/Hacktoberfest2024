// Java Program to find common elements 
// in two ArrayLists 
// Using retainAll() method 

// import ArrayList package 
import java.util.ArrayList; 

public class GFG { 

	// main method 
	public static void main(String[] args) 
	{ 

		// create ArrayList list1 
		ArrayList<String> 
			list1 = new ArrayList<String>(); 

		// Add values in ArrayList 
		list1.add("Hii"); 
		list1.add("Geeks"); 
		list1.add("for"); 
		list1.add("Geeks"); 

		// print list 1 
		System.out.println("List1: "
						+ list1); 

		// Create ArrayList list2 
		ArrayList<String> 
			list2 = new ArrayList<String>(); 

		// Add values in ArrayList 
		list2.add("Hii"); 
		list2.add("Geeks"); 
		list2.add("Gaurav"); 

		// print list 2 
		System.out.println("List2: "
						+ list2); 

		// Find the common elements 
		list1.retainAll(list2); 

		// print list 1 
		System.out.println("Common elements: "
						+ list1); 
	} 
} 
 
