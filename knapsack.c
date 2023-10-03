/*Write a program to find the maximum profit nearest to but not
exceeding the given knapsack capacity using the Fractional Knapsack algorithm.
Notes# Declare a structure ITEM having data members item_id, item_profit, item_weight and
profit_weight_ratio. Apply heap sort technique to sort the items in non-increasing order,
according to their profit /weight.
Input:

Enter the number of items: 3
Enter the profit and weight of item no 1: 27 16
Enter the profit and weight of item no 2: 14 12
Enter the profit and weight of item no 3: 26 13
Enter the capacity of knapsack:18

Output:

Item No profit Weight Amount to be taken
3 26.000000 13.000000 1.000000
1 27.000000 16.000000 0.312500
2 14.000000 12.000000 0.000000
Maximum profit: 34.437500*/
#include <stdio.h>
#include <stdlib.h>

struct Item {
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
};

void heapify(struct Item items[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && items[left].profit_weight_ratio > items[smallest].profit_weight_ratio)
        smallest = left;

    if (right < n && items[right].profit_weight_ratio > items[smallest].profit_weight_ratio)
        smallest = right;

    if (smallest != i) {
        
        struct Item temp = items[i];
        items[i] = items[smallest];
        items[smallest] = temp;

        heapify(items, n, smallest);
    }
}


void heapSort(struct Item items[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(items, n, i);

    for (int i = n - 1; i >= 0; i--) {
        
        struct Item temp = items[0];
        items[0] = items[i];
        items[i] = temp;

        heapify(items, i, 0);
    }
    
}
void bsortDesc(struct Item list[], int s)
{
    int i, j;
    struct Item temp;
    
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (list[j].profit_weight_ratio < list[j + 1].profit_weight_ratio)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            } 
        }
    }
}
void fractionalKnapsack(struct Item items[], int n, double capacity) {
    heapSort(items, n);
    bsortDesc(items, n);
    double max_profit = 0.0;
    printf("\nItem No profit Weight Amount to be taken\n");

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].item_weight) {
            printf("%d %.6lf %.6lf 1.000000\n", items[i].item_id, items[i].item_profit, items[i].item_weight);
            max_profit += items[i].item_profit;
            capacity -= items[i].item_weight;
        } else {
            double fraction = capacity / items[i].item_weight;
            printf("%d %.6lf %.6lf %.6lf\n", items[i].item_id, items[i].item_profit, items[i].item_weight, fraction);
            max_profit += items[i].item_profit * fraction;
            break;
        }
    }

    printf("Maximum profit: %.6lf\n", max_profit);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%lf %lf", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    double capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%lf", &capacity);

    fractionalKnapsack(items, n, capacity);

    return 0;
}
