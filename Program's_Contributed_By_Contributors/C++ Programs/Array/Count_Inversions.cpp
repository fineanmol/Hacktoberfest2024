#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    //Counter to keep the count of inversions.
    long long my_counter = 0;
    
    
    void merge(long long a[], long long p, long long q, long long r){
        long long l = q-p+1;
        long long a1[l];
    
        long long l2 = r-q;
        
        long long a2[l2];
        
        
        for(long long i = 0;i<l;i++){
            a1[i] = a[i+p];
        }
        
        for(long long i = 0;i<l2;i++){
            a2[i] = a[q+i+1];
        }
        
        long long left = 0, right = 0, k = p;
        
        
        while(left < l && right < l2)
        {
            
            if(a1[left] <= a2[right]){
                a[k] = a1[left];
                left++;
            }
            else{
                a[k] = a2[right];
                right++;
                my_counter += (l-left); 
            }
            k++;
        }
        
        while(left < l){
            a[k++] = a1[left++];
        }
       
        while(right < l2){
            
            a[k++] = a2[right++];
        }
    }

    
    void mergeSort(long long a[], long long p, long long r)
    {
        if(p < r)
        {
            long long q = (p+r)/2;
            
            mergeSort(a, p, q);
            
            mergeSort(a, q+1, r);
            
            merge(a, p, q, r);
        }
    }
    
  
    long long int inversionCount(long long arr[],long long N)
    {
        mergeSort(arr,0,N-1);
        long long int res = my_counter;
        my_counter = 0;
        return res;
    }

};

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
