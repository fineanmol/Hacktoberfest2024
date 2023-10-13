public class mostwater {
    public static void main(String[] args) {
        int []a ={2,3,4,5,18,17,6};
        int n = a.length ;
        int as =0,res =0 ;

        for(int j = n-1 ;j>0 ;j--) {
            for (int i = 0; i < n - 2; i++) {
                res = min(a, i, j) * (j - i);
                if (as < res)
                    as = res;
            }
        }
        System.out.println(as);

    }

    public static int  min(int[]a ,int x,int y) {
        if(a[x]<=a[y])
            return a[x];
        else return a[y];
    }
}
