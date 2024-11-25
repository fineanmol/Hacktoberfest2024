#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    float a, b, c, d, root1, root2, real_part, imaginary_part;
    printf("\nENTER THE CO-EFFICIENTS OF THE QUADRATIC EQUATIONS\n");
    scanf("%f\n%f\n%f", &a, &b, &c);
    d = b * b - (4 * a * c);
    if (d > 0)
    {
        root1 = (-b + sqrt(d)) / (2 * a);
        root2 = (-b - sqrt(d)) / (2 * a);
        printf("Root 1=%f", root1);
        printf("\nRoot 2=%f", root2);
    }
    else if (d == 0)
    {
        root1 = root2 = -b / (2 * a);
        printf("Root1=%f", root1);
        printf("\nRoot2=%f", root2);
    }
    else
    {
        real_part = -b / (2 * a);
        imaginary_part = sqrt(-d) / (2 * a);
        printf("Root1=\nReal part= %f", real_part);
        printf("\nImaginary part=%f", imaginary_part);
        printf("\nRoot 2=\nReal part=%f", real_part);
        printf("\nImaginary part=%f", -imaginary_part);
    }
    getch();
    return 0;
}
