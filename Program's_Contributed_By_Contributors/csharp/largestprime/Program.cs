/*
a very tiny program in C#
*/

using System;

namespace solution1
{
    class Program
    {

        static int getInitNumber(int n)
        {
            return (int) Math.Pow(10,n);
        }

        static bool isPrime(int num)
        {
            int count = 2;
            bool prime = true;

            while ((prime) && (count!=num))
            {
                if (num % count == 0)
                {
                    prime = false;
                }
                count++;
            }
        
            return prime;
        }


        static int largestprime(int n){
            int val = 0;
            int initNumber = getInitNumber(n);
            int lastNumber = getInitNumber(n + 1);
            
            for (int i = initNumber; i< lastNumber; i++) 
            {
                if (isPrime(i))
                {
                    val = i;
                }
            }
            
            return val;
        }


        static void Main(string[] args)
        {
            //test number
            int n = 2;

            Console.WriteLine("Largest Prime:" + largestprime(n));
        }
    }
}
