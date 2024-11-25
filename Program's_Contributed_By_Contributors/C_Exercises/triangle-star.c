#include <stdio.h>
#include <math.h>

int main(void)
{
    int b, h;
    printf("Base (rows): ");
    scanf("%d", &b);
    printf("Height (columns): ");
    scanf("%d", &h);

    int starIncr = round((float)b / (float)(h-1));
    if(starIncr == 0) starIncr++;
    printf("Numero di stelline da aggiungere per riga: %d\n", starIncr);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if(starIncr > 1 && j == 0) {
                printf("*");
                continue;
            } 
            for (int k = 0; k < starIncr; k++)
                printf("*");
        }
        printf("\n");
    }
}