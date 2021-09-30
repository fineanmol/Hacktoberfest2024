using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace Sorting_Algorithms_In_C_Sharp
{
    public static class BucketSort
    {
        //Bucket sort breaks a list down into sub-lists, you can then use another algo to sort the sub-lists
        //Bucketsort isn't a good choice if you don't know the range or distribution of the data
        //Bucket Sort time complexity
        //Average case: O(n+k) - k being the number of buckets that were created
        //Worst case: O(N^2)
 
        //In this case, we will focus on building an algorithm that uses bucketsort to sort an array of integers between 1 and 99
        //we will also assume that the integers in the passed array are evenly distributed
        public static List<int> BucketSort1(params int[] x)
        {
            List<int> result = new List<int>();
 
            //Determine how many buckets you want to create, in this case, the 10 buckets will each contain a range of 10
            //1-10, 11-20, 21-30, etc. since the passed array is between 1 and 99
            int numOfBuckets = 10;
 
            //Create buckets
            List<int>[] buckets = new List<int>[numOfBuckets];
            for (int i = 0; i < numOfBuckets; i++)
                buckets[i] = new List<int>();
 
            //Iterate through the passed array and add each integer to the appropriate bucket
            for (int i = 0; i < x.Length; i++)
            {
                int buckitChoice = (x[i] / numOfBuckets);
                buckets[buckitChoice].Add(x[i]);
            }
 
            //Sort each bucket and add it to the result List
            //Each sublist is sorted using Bubblesort, but you could substitute any sorting algo you would like
            for (int i = 0; i < numOfBuckets; i++)
            {
                int [] temp = BubbleSortList(buckets[i]);
                result.AddRange(temp);
            }
            return result;
        }
 
        //Bubblesort w/ ListInput
        public static int[] BubbleSortList(List<int> input)
        {
            for (int i = 0; i < input.Count; i++)
            {
                for (int j = 0; j < input.Count; j++)
                {
                    if (input[i] < input[j])
                    {
                        int temp = input[i];
                        input[i] = input[j];
                        input[j] = temp;
                    }
                }
            }
            return input.ToArray();
        }
        ////Call in Program.cs to test
        //int[] x = new int[] { 99, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 5, 1 };
        //List<int> sorted = Bucket_Sort.BucketSort(x);
        //foreach (int i in sorted)
        //    Console.WriteLine(i);
    }
}