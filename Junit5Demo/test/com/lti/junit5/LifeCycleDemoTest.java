package com.lti.junit5;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.*;

import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.api.TestInstance.Lifecycle;
@TestInstance(Lifecycle.PER_CLASS)
class LifeCycleDemoTest {
	
	
	
	
	//Book book;
	public LifeCycleDemoTest ()
	{
		System.out.println("constructor  \n");
	}
	@BeforeAll	
	//static void beforeAllMethod() 
 void beforeAllMethod() 
	{
		System.out.print("Before All  \n");
	}
	@AfterAll
	//static void afterAllMethod()
	 void afterAllMethod()
	{
		System.out.print("Universal After All Method \n");
	}
	
@BeforeEach
void  beforeEachMethod()
{
	System.out.print("Before Each \n");
}
	
	@AfterEach
	void afterEachMethod()
	{
		System.out.print("After Each \n");
	}
	
	
	
@Test
void testMethod1()
{
	System.out.print("Test method1 \n");
}

@Test
void testMethod2()
{
	

	System.out.print("Test Method2 \n");
}
}
