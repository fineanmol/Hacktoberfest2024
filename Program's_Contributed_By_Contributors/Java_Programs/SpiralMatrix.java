//Coded by shreeyachatzz
import java.util.Scanner;//To Import Scanner Class
 
public class Spiral
 {
    public static void main(String args[])
    {
        System.out.println("Enter the number of rows and columns (no. of rows and columns are the same and less than 10) : ");
        //To accept number of rows and columns 
         
        Scanner sc = new Scanner(System.in);
         
        int r = sc.nextInt();
        
         
        int[][] spiral = new int[r][r];//To initialize a 2d array
         
        int value = 1;
         
        int minCol = 0;
         
        int maxCol = r-1;
         
        int minRow = 0;
         
        int maxRow = r-1;
        System.out.println("The Spiral Array (CLOCKWISE) IS: \n ");
        //Syntax for Spiral Array Formation     
        while (value <= r*r)
        {
            for (int i = minCol; i <= maxCol; i++)
            {
                spiral[minRow][i] = value;
                     
                value++;
            }
             
            for (int i = minRow+1; i <= maxRow; i++) 
            { 
                spiral[i][maxCol] = value; 
                 
                value++; 
            } 
             
            for (int i = maxCol-1; i >= minCol; i--)
            {
                spiral[maxRow][i] = value;
                             
                value++;
            }
             
            for (int i = maxRow-1; i >= minRow+1; i--) 
            {
                spiral[i][minCol] = value;
                 
                value++;
            }
             
            minCol++;
             
            minRow++;
             
            maxCol--;
             
            maxRow--;
        }
         
        for (int i = 0; i < spiral.length; i++)
        {
            for (int j = 0; j < spiral.length; j++)
            {
                System.out.print(spiral[i][j]+ "\t");
            }
             
            System.out.println();
        }
    }
}
/* OUTPUT:
Enter the number of rows and columns (no. of rows and columns are the same and less than 10) : 
9

The Spiral Array (CLOCKWISE) IS: 
 
1	2	3	4	5	6	7	8	9	
32	33	34	35	36	37	38	39	10	
31	56	57	58	59	60	61	40	11	
30	55	72	73	74	75	62	41	12	
29	54	71	80	81	76	63	42	13	
28	53	70	79	78	77	64	43	14	
27	52	69	68	67	66	65	44	15	
26	51	50	49	48	47	46	45	16	
25	24	23	22	21	20	19	18	17
	
*/
