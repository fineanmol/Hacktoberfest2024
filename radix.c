#include <stdio.h>

int findMax(int array[], int size) {
    int maxVal = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > maxVal)
            maxVal = array[i];
    return maxVal;
}

void digitSort(int array[], int size, int exp) {
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void sortRadix(int array[], int size) {
    int maxVal = findMax(array, size);

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        digitSort(array, size, exp);
}

void displayArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int array[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    sortRadix(array, n);
    printf("Sorted array: ");
    displayArray(array, n);
    return 0;
}
