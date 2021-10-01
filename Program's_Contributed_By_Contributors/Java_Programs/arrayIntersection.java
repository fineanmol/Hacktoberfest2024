public class arrayIntersection{

    public static void intersect(int[] a,int[] b){

        int minSize = (a.length>=b.length) ? b.length:a.length;
        int c[] = new int[minSize];
        int z=0;
        for(int i=0;i<a.length;i++){

            for(int j=0;j<b.length;j++){

                if(a[i]==b[j]){

                    if(search(c, a[i])==-1){
                        c[z]=a[i];
                        z++;
                    }
                }
            }
        }


    }

    public static int search(int arr[],int a){

        int start=0,end=arr.length-1;

        while(start<=end){

            int mid=(start+end)/2;
            if(arr[mid]>a){
                end=mid-1;
            }else if(arr[mid]<a){
                start = mid+1;
            }else{
                return mid;
            }

        }

        return -1;
    }

    public static void main(String[] args) {
        
        int arr1[] = { 1,2,3,4,5,6,7,8,9,10};
        int arr2[] = { 5,6,7,8,9,10,11,12,13,14,15,16};
        intersect(arr1,arr2);
    }
}