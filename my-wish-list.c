#define _CRT_SECURE_NO_WARNINGS
#define ITEMNUM 10

#include <stdio.h>

int main(void)
{
    const double minIncome = 500.00, maxIncome = 400000.00, minCost = 100.00;
    double myIncome = 0.0, annualIncome = 0.0, totalCost = 0, filteredTotalCost = 0.0, forecastMonthResult = 0.0;
    int flag = 1, myItems = 0, i, menuSelect = 0, filterSelect = 0, isFinancing = 0;

    double costArray[ITEMNUM]; // set max 
    int priorityArray[ITEMNUM];
    char financingArray[ITEMNUM];


    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");


    while (flag)
    {
        printf("\n");
        printf("Enter your monthly NET income: $");
        scanf("%lf", &myIncome);

        if (myIncome >= minIncome && myIncome <= maxIncome)
        {
            flag = 0;
        }
        else if (myIncome <= 0)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", minIncome);

        }
        else if (myIncome > maxIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", maxIncome);
        }
    }
    flag = 1;

    while (flag)
    {
        printf("\n");
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &myItems);

        if (myItems >= 1 && myItems <= ITEMNUM)
        {
            flag = 0;
        }
        else
        {
            printf("ERROR: List is restricted to between 1 and %d items.\n", ITEMNUM);

        }
    }

    for (i = 0; i < myItems; i++)
    {
        flag = 1;
        printf("\n");
        printf("Item-%d Details:\n", i + 1);

        while (flag)
        {
            printf("   Item cost: $");
            scanf("%lf", &costArray[i]);

            if (costArray[i] >= minCost)
            {
                totalCost += costArray[i];
                flag = 0;
            }
            else
            {
                printf("      ERROR: Cost must be at least $%.2lf\n", minCost);

            }
        }
        flag = 1;

        while (flag)
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priorityArray[i]);

            if (priorityArray[i] >= 1 && priorityArray[i] <= 3)
            {
                flag = 0;
            }
            else
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        }
        flag = 1;

        while (flag)
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financingArray[i]); //one space before %c

            if (financingArray[i] == 'y' || financingArray[i] == 'n')
            {
                flag = 0;
            }
            else
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        }
    }
    printf("\n");
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 0; i < myItems; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priorityArray[i], financingArray[i], costArray[i]);

    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", totalCost);
   
    flag = 1;

    while (flag)
    {
        annualIncome = myIncome * 12;
        // reinitializing 
        filteredTotalCost = 0;
        isFinancing = 0;
        
        printf("\n");
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &menuSelect);

        if (menuSelect == 1)
        {
            forecastMonthResult = (int)(totalCost * 100) % (int)(annualIncome * 100) / 100 / myIncome + 0.5;
               
            printf("\n");
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", totalCost); 
            printf("Forecast: %d years, %.0lf months\n", (int)(totalCost / annualIncome), forecastMonthResult); 

            for (i = 0; i < myItems; i++)
            {
                if (financingArray[i] == 'y')
                {
                    isFinancing = 1;
                }

            }

            if (isFinancing == 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
                printf("====================================================\n");

            }
            else
            {
                printf("====================================================\n");
            }

        }
        else if (menuSelect == 2)
        {
            printf("\n");
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &filterSelect);
            printf("\n");
            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", filterSelect);

            for (i = 0; i < myItems; i++)
            {

                if (priorityArray[i] == filterSelect)
                {
                    filteredTotalCost += costArray[i];
                }

            }

            if (filteredTotalCost < annualIncome)
            {
                forecastMonthResult = filteredTotalCost / myIncome;
            }
            else
            {
                forecastMonthResult = (int)(filteredTotalCost * 100) % (int)(annualIncome * 100) / 100 / myIncome + 0.5;

            }

            printf("Amount:   $%.2lf\n", filteredTotalCost);
            printf("Forecast: %d years, %.0lf months\n", (int)(filteredTotalCost / annualIncome), forecastMonthResult);

            for (i = 0; i < myItems; i++) 
            {
                if (priorityArray[i] == filterSelect && financingArray[i] == 'y')
                {
                    isFinancing = 1;
                }
            }

            if (isFinancing == 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
                printf("====================================================\n");

            }
            else
            {
                printf("====================================================\n");
            }
        }
        else if (menuSelect == 0)
        {
            printf("\n");
            printf("Best of luck in all your future endeavours!\n");

            flag = 0;

        }
        else
        {
            printf("\n");
            printf("ERROR: Invalid menu selection.");
            printf("\n");

        }
    }   

    return 0;
}