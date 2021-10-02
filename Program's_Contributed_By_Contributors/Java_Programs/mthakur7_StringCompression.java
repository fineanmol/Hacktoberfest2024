//--------------------PROBLEM STATEMENT-----------------------------------------------------------------------
/*
1. You are given a string. 
2. You have to compress the given string in the following two ways - 
   First compression -> The string should be compressed such that consecutive duplicates of characters are replaced with a single character.
   For "aaabbccdee", the compressed string will be "abcde".
   Second compression -> The string should be compressed such that consecutive duplicates of characters are replaced with the character and followed by the number of consecutive duplicates.
   For "aaabbccdee", the compressed string will be "a3b2c2de2".
*/

//---------------------INPUT FORMAT----------------------------------------------------------------------------
//A String

//---------------------OUTPUT FORMAT----------------------------------------------------------------------------
//Two strings representing first compressed string and second compressed string respectively.

//--------------------SOUTION-------------------------------------------------------------------------------------
import java.io.*;
import java.util.*;

public class Main {

	public static String compression1(String str){
		// write your code here

String s=""+str.charAt(0);
  for(int i=1;i<str.length();i++){
      if(str.charAt(i)!=str.charAt(i-1))
      s=s+str.charAt(i);
      }
		return s;
	}

	public static String compression2(String str){
		// write your code here

String s=""+str.charAt(0);
  int k=1;
  for(int i=1;i<str.length();i++){
    
      if(str.charAt(i)==str.charAt(i-1)){
         k++;   
      }else{
          if(k>1)
           s=s+Integer.toString(k)+str.charAt(i);
           else
             s=s+str.charAt(i);
           k=1;
      }
  }
 
  if(k!=1)
  s=s+Integer.toString(k);
		return s;
	}
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		System.out.println(compression1(str));
		System.out.println(compression2(str));
	}

}
