bool isPossible(vector<int> arr,int n,int m,int mid){
   int studentCount = 1;
   int pageSum = 0; //pageSum tells total pages for current Student(from pageCount)
   for(int i=0;i<n;i++){
       if(pageSum + arr[i]<=mid){
           pageSum += arr[i];
       }
       else{
           studentCount++;
           if(studentCount>m || arr[i]>mid){
             //exceeded student limit  or current book page>mid
               return false;
           }
           pageSum = arr[i];
       }
   }
   return true;
}
int allocateBooks(vector<int> arr, int n, int m) {
   // Write your code here.
   int s = 0;
   int sum = 0;
   for(int i=0;i<n;i++){
       sum+=arr[i];
   }
   int e = sum;
   int ans = -1;
   int mid = s + (e-s)/2;
   
   while(s<=e){
       if(isPossible(arr,n,m,mid)){ 
           //possible solution exist hence move left
           ans = mid;
           e = mid - 1;
       } else {
           //no possible solution, move right
           s = mid + 1;
       }
       mid = s + (e-s)/2;
   }
   return ans;
}
