#include <stdio.h>
int main()
{
    int Qty, i;
    int *v;
    printf("Quantity: ");
    scanf("%d", &Qty);
    v = malloc(Qty * sizeof(int)); // malloc return pointer
    if (v == NULL)
    {
        printf("Not enough memory");
        return 0;
    }

    for (i = 0; i < Qty; i++)
    {
        printf("Put the element %d of the vector: ", i);
        scanf("%d", &v[i]);
    }

    // showing dymanic vector

    for (i = 0; i < Qty; i++)
    {
        printf("\nv[%d]=%d", i, v[i]);
    };
    free(v);

    // check the vector after destroyed
    for (i = 0; i < Qty; i++)
    {
        printf("\nv[%d]=%d", i, v[i]);
    }
    // check memory
    // repeat

    getch();
}
