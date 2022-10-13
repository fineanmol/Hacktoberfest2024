#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void insert_soldiers(List *list);
int insert_jump();
void show_soldiers(List *list);
void popular_list(List *list, int total_soldiers);
void remove_soldier(List *list, int soldier_number);
void josefo(List *list, int jump);

void show_soldiers(List *list)
{
    Node *item = list->head->next;
    int c;

    printf("Soldiers: ");
    for (c = 0; c < list->size; c++)
    {
        printf("%d ", item->num);
        item = item->next;
    }
    printf("\n");
}

void insert_soldiers(List *list)
{
    int resp_soldiers, test, ch;

    printf("Insert soldiers number(insert 0 exit stops program): ");
    test = scanf("%d", &resp_soldiers);
    printf("\n");
    while (test == 0)
    {
        fprintf(stderr, "Invalid value. Insert an integer number!\n");
        printf("Insert soldiers number(insert 0 exit stops program): ");
        do
        {
            ch = getchar();
        } while ((ch != EOF) && (ch != '\n'));
        test = scanf("%d", &resp_soldiers);
        printf("\n");
    }
    if (resp_soldiers != 0)
    {
        popular_list(list, resp_soldiers);
    }
    else
    {
        printf("Bye!\n");
    }
}

int insert_jump()
{
    int resp_jumps, test, ch;

    while (1)
    {
        printf("Insert jump size (except 0): ");
        test = scanf("%d", &resp_jumps);
        while (test == 0)
        {
            fprintf(stderr, "Invalid value. Insert an integer number!\n");
            printf("Insert jump size (except 0): ");
            do
            {
                ch = getchar();
            } while ((ch != EOF) && (ch != '\n'));
            test = scanf("%d", &resp_jumps);
        }
        if (resp_jumps == 0)
        {
            printf("Jump cannot be 0\n");
        }
        else
        {
            // josefo(list, resp_jumps);
            // break;
            return resp_jumps;
        }
    }
}

void popular_list(List *list, int total_soldiers)
{
    int c;

    for (c = 1; c < total_soldiers + 1; c++)
    {
        Node *soldier = (Node *)malloc(sizeof(Node));
        if (list->size == 0)
        {
            soldier->next = list->head;
            soldier->previous = list->head;
            soldier->num = c;
            list->head->next = soldier;
            list->head->previous = soldier;
            list->size++;
        }
        else
        {
            soldier->next = list->head;
            soldier->previous = list->head->previous;
            soldier->num = c;
            list->head->previous->next = soldier;
            list->head->previous = soldier;
            list->size++;
        }
    }
    show_soldiers(list);
}

void remove_soldier(List *list, int soldier_number)
{
    Node *item = list->head->next;
    int c = 0;

    while (c < list->size)
    {
        if (soldier_number == item->num)
        {
            printf("Removed soldier: %d\n", item->num);
            item->previous->next = item->next;
            item->next->previous = item->previous;
            list->size--;
            free(item);
            show_soldiers(list);
            break;
        }
        else
        {
            item = item->next;
        }
        c++;
    }
}

void josefo(List *list, int jump)
{
    Node *aux;
    if (jump > 0)
    {
        Node *item = list->head->next;
        int c = 1;

        while (1)
        {
            if (item->num != 0)
            {
                if (list->size == 1)
                {
                    printf("The last soldier is %d\n", item->num);
                    break;
                }
                if (c == jump)
                {
                    aux = item->next;
                    remove_soldier(list, item->num);
                    c = 1;
                    item = aux;
                    jump = insert_jump();
                }
                else
                {
                    item = item->next;
                    c++;
                }
            }
            else
            {
                item = item->next;
            }
        }
    }
    else
    {
        // Lê a list ao contrário
        Node *item = list->head->previous;
        int c = -1;

        while (1)
        {
            if (item->num != 0)
            {
                if (list->size == 1)
                {
                    printf("The last soldier is %d\n", item->num);
                    break;
                }

                if (c == jump)
                {
                    aux = item->previous;
                    remove_soldier(list, item->num);
                    c = -1;
                    item = aux;
                    jump = insert_jump();
                }
                else
                {
                    item = item->previous;
                    c--;
                }
            }
            else
            {
                item = item->previous;
            }
        }
    }
}
