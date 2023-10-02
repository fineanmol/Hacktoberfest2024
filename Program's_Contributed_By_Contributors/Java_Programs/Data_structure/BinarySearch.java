public class BinarySearch {
    public static void main(String[] args)
    {
        static int Binary(int[] arr, int target , int start, int end)
        {
            int start=0;
            int end=arr.length-1;
            while(start<=end)
            {
                int mid= start+(end-start)/2;
                if(target<arr[mid])
                {
                    end=mid-1;
                }
                elseif(target>arr[mid])
                {
                    start=mid+1;
                }
                else{
                    return mid;
                }
            }
            return -1;
        }
    }    
}
