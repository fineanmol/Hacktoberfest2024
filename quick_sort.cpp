int partition(int a[], int si, int ei){
    int count = 0;
    int x = a[si];
    for(int i = si+1; i<=ei ; i++){
        if(a[i]<=x)
            count++;
    }
    int temp;
    temp = a[si];			// putting x at its correct position
    a[si] = a[si+count];
    a[si+count] = temp;
    int i = si;
    int j = ei;
    while(i<si+count || j>si+count){
        if(a[i]<=x)
            i++;
        else if(a[j]>x)
            j--;
        else{
            temp = a[i];		// swapping a[i] and a[j]
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    return si+count;
}

void quickSort1(int a[], int start, int end)
{
    // your code goes here 
    if(start>=end)
        return;
    int c = partition(a, start, end);
    quickSort1(a, start, c-1);
    quickSort1(a, c+1, end);
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    quickSort1(input, 0, size - 1);

}
