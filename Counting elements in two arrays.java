class Solution
{
    public static ArrayList<Integer> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
    {
       // add your code here
       Arrays.sort(arr2);
       ArrayList<Integer> list = new ArrayList<>();
       for(int i=0; i<m; i++){
           if(arr1[i]>=arr2[n-1]){
               list.add(n);
               continue;
           }
           int l = 0; int r = n-1;
           while(l<=r){
               int mid = (l+r)/2;
               if(arr2[mid]>arr1[i]){
                   r=mid-1;
               }
               else{
                   l=mid+1;
               }
           }
           list.add(l);
       }
       return list;
    }
}
