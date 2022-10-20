#include <stdio.h>
#include <math.h>

void main()
{
    float a, b, c, delta, sr_delta;

    printf("\nBHASKARA\n\n");
    printf("\nPut the value of A: ");
    scanf("%f", &a);
    printf("\nPut the value of B: ");
    scanf("%f", &b);
    printf("\nPut the value of C: ");
    scanf("%f", &c);

    delta = (pow(b, 2) - 4 * a * c);

    if (delta >= 0)
    {
        if (delta == 0)
        {
            printf("\nThe square root x1=%f", ((-b + sqrt(delta)) / 2 * a));
        }
        else
        {
            printf("\nThe square root x1=%f", ((-b + sqrt(delta)) / 2 * a));
            printf("\nThe square root x2=%f", ((-b - sqrt(delta)) / 2 * a));
        }
    }
    else
    {
        delta = fabs(delta);
        sr_delta = sqrt(delta);

        printf("\nThe square root x1=%f+%fi", ((-b) / 2 * a), ((sr_delta) / 2 * a));
        printf("\nThe square root x2=%f-$fi", ((-b) / 2 * a), ((sr_delta) / 2 * a));
    }
    getch();
}
