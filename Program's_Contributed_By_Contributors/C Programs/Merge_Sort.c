#include<stdio.h>
#include<stdlib.h>

void mergeArray(int a[], int start1, int end1, int start2, int end2);
void mergeSort(int a[], int start, int end);
void print(int a[], int n);

void main()
{
    int length, start1, end1, end2, i;
    printf("Welcome to Merge Sort!!\n");
    printf("You can sort the data elements here, I will help you in that\n");
    printf("So lets start with sorting integer datatypes\n");
    printf("So let me know the how much total integer datatypes you want me to sort:\n");
    scanf("%d", &length);

    int *a = (int *) calloc (length, sizeof(int));

    printf("So how are you going to break the array of %d length into?\n", length);
    printf("So let me know the length of the first array:\n");
    scanf("%d", &end1);

    while(end1 > length)
    {
        printf("Please enter a valid range!! You decided to create an array out of bound!!\nPlease enter an integer within %d:\n", length);
        scanf("%d", &end1);
    }

    end2 = length - end1;
    printf("Hence the length of the another array will be %d\n", end2);

    printf("Now you can enter the elements for the first array:\n");
    for ( i = 0; i < end1; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Now enter the elements for the Second array:\n");
    for ( i = end1; i < length; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("So you have entered the First array as follows:\n");
    print(a, end1);

    printf("And now the whole array entered by you is as follows {UNSORTED ARRAY} :\n");
    print(a, length);
    printf("The length of the full array is: %d\n", length);

    mergeSort(a, 0, length);

    // SORTED ARRAY
    print(a, length);

}

void mergeArray(int a[], int start1, int end1, int start2, int end2)
{
    int i, j, k;
    int *temp = NULL;
    temp = (int *) calloc ((end1+end2), sizeof(int));
    i = start1;
    j = start2;
    k = 0;

    while (i <= end1 && j <= end2)
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while( i <= end1 )
        temp[k++] = a[i++];

    while( j <= end2 )
        temp[k++] = a[j++];

    for(i = start1, j = 0; i <= end2; i++, j++)
        a[i] = temp[j];
}

void mergeSort(int a[], int start, int end)
{
    int middle;
    if(start < end)
    {
        middle = (start + end) / 2;

        mergeSort(a, start, middle);
        mergeSort(a, middle + 1, end);
        mergeArray(a, start, middle, middle+1, end);
    }

}

void print(int a[], int n)
{
    int i;
    printf("So now Printing the Array below:\n");

    for ( i = 0; i < n; i++)
    {
        printf("%c%4d%c\n", 221, a[i], 222);
    }
}
