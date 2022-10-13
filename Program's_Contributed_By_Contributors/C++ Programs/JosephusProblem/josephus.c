/*
João Luiz Mineiro Alves
Fernando Soares de Araújo Filho
José Fhilipe Martins Coelho
*/

#include "functions.h"

int main()
{
    // Aloca memória pra lista e pro nó dentro dela e define os valores padrões.
    List *soldiers_list = (List *)malloc(sizeof(List));
    soldiers_list->head = (Node *)malloc(sizeof(Node));

    soldiers_list->head->previous = soldiers_list->head;
    soldiers_list->head->next = soldiers_list->head;
    soldiers_list->head->num = 0;
    soldiers_list->size = 0;

    insert_soldiers(soldiers_list);
    josefo(soldiers_list, insert_jump(soldiers_list));

    return 0;
}
