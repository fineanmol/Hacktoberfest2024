class SpiralMatrix 
{  
    //defining method to print the spiral pattern or matrix  
    static void printSpiralPattern(int size)  
    {  
        //create two variables row and col to traverse rows and columns  
        int row = 0, col = 0;  
        int boundary = size - 1;  
        int sizeLeft = size - 1;  
        int flag = 1;  
        //variables r, l, u and d are used to determine the movement  
        // r = right, l = left, d = down, u = upper  
        char move = 'r';  
        //creating a 2D array for matrix  
        int[][] matrix =new int [size][size];  
        for (int i = 1; i < size * size + 1; i++)  
        {  
            //assigning values  
            matrix[row][col] = i;  
        //switch-case to determine the next index  
        switch (move)  
        {  
        //if right, go right  
        case 'r':  
            col += 1;  
            break;  
        //if left, go left  
        case 'l':  
            col -= 1;  
            break;  
        //if up, go up  
        case 'u':  
            row -= 1;  
            break;  
        //if down, go down  
        case 'd':  
            row += 1;  
            break;  
        }   
        if (i == boundary)  
        {  
            //adds the left size for the next boundary  
            boundary = boundary + sizeLeft;  
            //decrease the size left by 1, if 2 rotations have been made  
            if (flag != 2)  
            {  
            flag = 2;  
            }  
            else  
            {  
            flag = 1;  
            sizeLeft -= 1;  
            }  
            //switch-case to rotate the movement  
            switch (move)  
            {  
            //if right, rotate to down  
            case 'r':  
                move = 'd';  
                break;  
            // if down, rotate to left  
            case 'd':  
                move = 'l';  
                break;  
            // if left, rotate to up  
            case 'l':  
                move = 'u';  
                break;  
            // if up, rotate to right  
            case 'u':  
                move = 'r';  
                break;  
            }  
        }  
        }  
        for (row = 0; row < size; row++)  
        {   
            for (col = 0; col < size; col++)  
                {  
                    int n = matrix[row][col];  
                    if(n < 10)  
                        System.out.print(n +" ");  
                    else  
                        System.out.print(n +" ");  
                }  
            System.out.println();  
        }  
    }  
    public static void main(String args[])  
    {  
        int size = 5;  
        System.out.println("Spiral Matrix or Pattern is: \n");   
        printSpiralPattern(size);  
    }  
}  