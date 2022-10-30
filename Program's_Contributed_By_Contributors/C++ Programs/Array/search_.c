#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int busca(int *vetor, long long int size, double number)
{
    if (number > vetor[size - 1])
        return size + 1;
    int esq = -1, dir = size;
    while (esq < dir - 1)
    {
        int half = (esq + dir) / 2;
        if (vetor[half] < number)
            esq = half;
        else
            dir = half;
    }
    return dir;
}

int main()
{
    long long int circ, tiro;
    long long int x, y;
    long long int sum = 0, b;
    int *raio;
    double a;

    scanf("%lld", &circ);
    if (circ <= 0)
        return 0;

    scanf("%lld", &tiro);
    if (tiro <= 0)
        return 0;

    raio = malloc(circ * sizeof(int));
    for (int i = 0; i < circ; i++)
    {
        scanf("%d", &raio[i]);
    }

    for (int j = 0; j < tiro; j++)
    {
        scanf("%lld %lld", &x, &y);
        a = sqrt((x * x) + (y * y));

        b = busca(raio, circ, a);

        if (b < circ)
            sum += (circ - b);
    }
    printf("%lld\n", sum);
    return 0;
}