{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
         if(low>high) return;
         int p=  partition(arr,low,high);
         quickSort(arr,low,p-1);
         quickSort(arr,p+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot=arr[high];
        int i=low,j=low-1;
        
        while(i<high)
        {
            if(arr[i]<=pivot)
            {
                swap(arr[i],arr[j]);
                j++;
            }
            i++;
        }
        
        swap(arr[j],arr[high]);
        return j;
       
    }
};
