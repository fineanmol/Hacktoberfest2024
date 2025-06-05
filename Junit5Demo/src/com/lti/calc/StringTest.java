package com.lti.calc;

public class StringTest {
	
	
	
public String ChangetoUpperCase(String str)
{
	
	if(str==null)
	{
		 return null;}
				 
		
		if (str.equals(" ")) {
			return " ";
		}
		
		return str.toUpperCase();
	

}

}
