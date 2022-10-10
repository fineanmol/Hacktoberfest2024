#include <stdio.h>
#include <stdlib.h>

void triangularNum(int num)
{
    printf("The triangular number of %d is: %d\n", num, num * (num + 1) / 2);
}

int main()
{
    int *pnum = (int *)malloc(sizeof(int));
    int num = 3;//change me;
    pnum = &num;
    triangularNum(*pnum);
    return 0;
}