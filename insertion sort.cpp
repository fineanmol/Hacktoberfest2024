void insertionSort(int *input, int size)
{
    //Write your code here
    for (int i = 1;i<size;i++)
    {
        int j,current=input[i];
        for(j=i-1;j>=0;j--){
            if(current <input[j])
                input[j+1] = input[j];
            else
                break;
        }
        input[j+1]=current;
    }
}
