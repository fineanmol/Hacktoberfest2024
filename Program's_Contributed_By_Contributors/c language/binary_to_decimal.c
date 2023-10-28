#include<stdio.h>
void main ()
{
	
	 int  num, decimal_num = 0, base = 1;  //add i and base=0
    printf (" Enter a binary number with the combination of 0s and 1s \n");  
    scanf (" %d", &num);
    /*for(i=num;i>0;i=i/10)
      {
      	decimal_num=decimal_num + (i%10)*pow(2,base);
      	base++;
	  }*/
	printf ( " The binary number is %d \t", num);       
    while ( num > 0)  
    {  
        
        decimal_num = decimal_num +(num % 10)* base;  
        num = num / 10;   
        base = base * 2;  
    } 
    printf (" \n The decimal number is %d \t", decimal_num);
}

