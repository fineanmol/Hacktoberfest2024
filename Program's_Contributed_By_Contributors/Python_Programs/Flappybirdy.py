// A sequence of integers seperated by space. Find max subsequence.

#include <stdio.h>
#include <string.h>

int main()
{
    char seq[100];
    int n=0, arr[50];
    int i,beg=0,end,endhere=0,j=0,k;
    printf("Enter sequence of integers, seperated by a whitespace");
    gets(seq);

    printf("%s \n",seq);

    // Returns first token
    char *token = strtok(seq, " ");
   
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        printf("%s\n", token);
        arr[j]=token;
        j++;
        token = strtok(NULL, " ");
    }

    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\nj=%d\n",j);

    int max=-9999,sum;
    for(i=0;i<j-1;i++)
    {
        sum=0;
        for(k=i;k<j-1;k++)
        {
            sum+=arr[k];
            if (sum>max)
                max=sum;
        }
    }
    printf("%d",max);

    return 0;
}
