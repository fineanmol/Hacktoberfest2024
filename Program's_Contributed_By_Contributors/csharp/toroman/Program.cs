/*
a very simple program
integer to roman numbers
*/

using System;

namespace toroman
{
  class Program
  {
        
    static string ToRoman(int v)
    {
        // MAX 3999
        string n = "";
        if (v == 0 || v > 3999) return n;
        if (v < 4) n = "I" + ToRoman(v - 1);
        else if (v == 4) n = "IV";
        else if (v < 9) n = "V" + ToRoman(v - 5);
        else if (v == 9) n = "IX";
        else if (v < 40) n = "X" + ToRoman(v - 10);
        else if (v < 50) n = "XL" + ToRoman(v - 40);
        else if (v < 90) n = "L" + ToRoman(v - 50);
        else if (v < 100) n = "XC" + ToRoman(v - 90);
        else if (v < 400) n = "C" + ToRoman(v - 100);
        else if (v < 500) n = "CD" + ToRoman(v - 400);
        else if (v < 900) n = "D" + ToRoman(v - 500);
        else if (v < 1000) n = "CM" + ToRoman(v - 9000);
        else if (v < 4000) n = "M" + ToRoman(v - 1000);
        return n;
    }

    static void ShowMessage(string text, string message)
    {
      Console.WriteLine(text + " " + message);
    }
    static void Main(string[] args)
    {
      int num = 1999; //sample number
      string roman = ToRoman(num);
      ShowMessage("Number to Roman: ", roman);
    }

  }
}


    