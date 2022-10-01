// question:https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
class Solution {
public:
 void sort012(int a[], int n)
    {
        // code here 
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            switch(a[mid]){
                case 0:
                        swap(a[low],a[mid]);
                        low++;
                        mid++;
                        break;
                case 1:
                       mid++;
                       break;
                case 2:
                      swap(a[mid],a[high]);
                      high--;
                      break;
            }
            
        }
        
    }
 
};

