#include <stdio.h>

struct data{
    int profit;
    int weight;
    float ratio;
};

float knapsack(struct data[], int t_weight){
    int i = 0;
    float t_profit = 0;
    while(t_weight > weight[i]){
        t_profit += profit[i];
        t_weight -= weight[i];
        i++;
        printf("%f\n", t_profit);
    }

    if(t_weight > 0){
        t_profit += (float)t_weight / weight[i] * profit[i];
    }

    return t_profit;
}

int main()
{
    int t_weight = 15;
    int n = 7;

    printf("Enter the number of Elements: ");
    scanf("%d", n);

    struct data d[10];
    printf("Enter profit and weight of Each elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", d[i].profit, d[i].weight);
        d[i].ratio = (float)d[i].profit/d[i].weight;
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if(d[j].ratio < d[j+1].ratio){
                int temp = d[j].ratio;
                d[j].ratio = d[j+1].ratio;
                d[j+1].ratio = temp;

                temp = d[j].profit;
                d[j].profit = d[j+1].profit;
                d[j+1].profit = temp;

                temp = d[j].weight;
                d[j].weight = d[j+1].weight;
                d[j+1].weight = temp;
            }
        }
    }
    
    float result = knapsack(d, t_weight);
    printf(">>>%f", result);
    
return 0;
}
