package com.lti.junit5;

import static org.junit.jupiter.api.Assertions.*;

import java.util.stream.Stream;

import org.junit.jupiter.api.*;
import org.junit.jupiter.params.*;
import org.junit.jupiter.params.provider.*;
import org.junit.jupiter.params.provider.EnumSource.Mode;
import org.junit.jupiter.params.provider.ValueSource;

import com.lti.bookstore.model.Colors;
import com.lti.calc.Calculator;
import com.lti.calc.StringTest;

class ParameterizedDemo {
@ParameterizedTest
@ValueSource(ints= {2,4,6,8,22,19,21})
void testEvenNumbers(int number)
{
	Calculator calculator=new Calculator();
	//assertTrue(calculator.isEvenNumber(2));
	//assertTrue(calculator.isEvenNumber(8));
	//assertTrue(calculator.isEvenNumber(4));
	//assertTrue(calculator.isEvenNumber(10));
//	assertTrue(calculator.isEvenNumber(6));
	assertTrue(calculator.isEvenNumber(number));
	
}

@ParameterizedTest
@ValueSource(strings= {"john","mike","raja"})
void testString(String name)
{
	
	assertEquals("john",name);
	}

@ParameterizedTest
//@NullSource
//@EmptySource
@NullAndEmptySource
void testNullSourceMethod(String str)
{
	StringTest stringTest=new StringTest();
assertEquals(null, stringTest.ChangetoUpperCase(str));
assertEquals(" ",str);

}
@ParameterizedTest

@NullAndEmptySource
void testNullAndEmptySourceMethod(String str)
{
StringTest stringTest=new StringTest();

assertEquals(str, stringTest.ChangetoUpperCase(str));
//assertEquals(" ",str);

}

@ParameterizedTest
@NullSource
@EmptySource
void testNullOrEmptySourceMethod(String str)
{
StringTest stringTest=new StringTest();

assertEquals(str, stringTest.ChangetoUpperCase(str));
}
@ParameterizedTest
//@CsvSource({"'a','A'"})
//@CsvSource({"'a','A'","'d','l'","'t','T'"})

@CsvSource({" ,  "})
void csvSourceMethod(String ip,String ep)
{
	StringTest stringTest=new StringTest();
    System.out.println(stringTest.ChangetoUpperCase(ip));
	//assertEquals(ep, stringTest.ChangetoUpperCase(ip));
   // assertEquals(" ",ip);
    assertNull(ep,()->stringTest.ChangetoUpperCase(ip));
}
@CsvFileSource(resources="/test.csv",numLinesToSkip = 2)
void csvFileSourceMethod(String input,String expect) {
	StringTest stringTest=new StringTest();
	assertEquals(expect, stringTest.ChangetoUpperCase(input));
}

@ParameterizedTest
//@EnumSource(value=Colors.class)
//@EnumSource(value=Colors.class,names= {"BLUE","YELLOW","BLACK"})
//@EnumSource(value=Colors.class,mode= Mode.EXCLUDE,names= {"BLUE","YELLOW","BLACK"})
@EnumSource(value=Colors.class,mode= Mode.MATCH_ALL,names="^(B|W).*$")
void enumSourceMethod(Colors colors) {
	assertNotNull(colors);
}


@ParameterizedTest
@MethodSource("stringProvider")
void methodSourceMethod(String names)
{
	assertEquals("Roger",names);
}
public static Stream<Arguments>  stringProviderArguments()
{
	
	return Stream.of(
			
			Arguments.arguments("a","A"),
			Arguments.arguments("b","B"),
			Arguments.arguments("c","C")
			);
			
}
@ParameterizedTest
@MethodSource("stringProviderArguments")
void argumentMethod(String ip,String ep)
{
	
	StringTest stringTest=new StringTest();
	assertEquals(ep, stringTest.ChangetoUpperCase(ip));

}

@RepeatedTest(5)
void simpleRepeatedTest()
{
	assertTrue(0<5);
}

@RepeatedTest(value=5,name="{displayName}= {currentRepetition}/{totalRepetitions}")
@DisplayName("Repetator Test No ")
void simpleRepeatedTest1()
{
	assertTrue(0<5);
}



}
