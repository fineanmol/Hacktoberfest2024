#include <stdio.h>

int main(int argc, char const *argv[])
{
    // create an program to sort an array
    int array[5] = {5, 4, 3, 2, 1};

    // sort the array
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    return 0;
}
