void selectionSort(int arr[], int n)
    {
       //code here
      for(int i=0;i<n-1;i++)
   {
       for(int j=i+1;j<n;j++)
       {
           if(arr[j]<arr[i])
           {
               swap(arr[i],arr[j]);
           }
       }
   }
        
       
       
    }