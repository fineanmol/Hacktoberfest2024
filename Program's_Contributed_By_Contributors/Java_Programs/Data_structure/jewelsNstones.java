public class jewelsNstones {
    public static void main(String[] args) {
        String jewels = "aA" ;
        String stones = "aAAbbbb" ;
        char[] a = jewels.toCharArray();
        char[] b = stones.toCharArray();
        int c=0;
        for(int i=0;i<a.length;i++)
        {
            for(int j=0;j<b.length;j++)
            {
                if(a[i] == b[j])
                {
                    c = c + 1;
                }
            }
        }
        System.out.println(c);
    }
}
