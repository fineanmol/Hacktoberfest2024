import java.util.*;
class pascals_triangle {
    public void getRow(int rowIndex) {
     rowIndex=rowIndex+1;
        int[][] result=new int[rowIndex][];
        for(int i=0;i < rowIndex;i++){
            int[] temp=new int[i+1];
            temp[0]=1;
            for(int j=0;j < i-1;j++){
                temp[j+1]=result[i-1][j] + result[i-1][j+1];
            }
            temp[temp.length-1]=1;
            result[i]=temp;
            
        }
        for(int i=0;i < result.length;i++){
            for(int j=0;j < result[i].length;j++){
                System.out.print(result[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        pascals_triangle x1 =new pascals_triangle();
        x1.getRow(3);
}
}