//Java program to check for
//identity matrix
public class IdentityMatrix
{
    public static void main(String[] args) {
        int rows, columns;
        boolean flag = true;

        //Initialize matrix a
        int arr[][] = {
                {1, 2, 1},
                {0, 1, 0},
                {1, 0, 1}
        };

        //Find out the
        //number of rows and columns
        //in the given matrix
        rows = arr.length;
        columns = arr[0].length;

        //Checks whether square matrix or not
        if(rows != columns){
            System.out.println("Enter a square matrix");
        }
        // For an identity matrix
        //Diagonal elements must equal 1
        //Others should equal 0
        else {
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    if(i == j && arr[i][j] != 1){
                        flag = false;
                        break;
                    }
                    if(i != j && arr[i][j] != 0){
                        flag = false;
                        break;
                    }
                }
            }

            if(flag)
                System.out.println("Given matrix is an identity matrix");
            else
                System.out.println("Given matrix is not an identity matrix");
        }
    }
}