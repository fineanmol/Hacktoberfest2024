public class patternGG{
    public static void main (String args[]){
        String s=" "; String str;
        for (int i=1;i<=6;i++)
        { 
            System.out.print(s);
            for(int j=i;j<=6;j++){
            System.out.print(j+" ");
            }
            System.out.println();
            s=s+" ";
        }
        
        for (int i=5;i>=1;i--)
        { 
            str=s.substring(0,s.length()-i);
            System.out.print(str);
            for(int j=i;j<=6;j++){
            System.out.print(j+" ");
            }
            System.out.println();
        
        }
        
    }}
