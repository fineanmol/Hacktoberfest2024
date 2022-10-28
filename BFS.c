#include <stdio.h>

#define MAXIMUM 10

void DFS(int i);

int adjecency_matrix[MAXIMUM][MAXIMUM];
int visited[10];
int no_of_vertices;

void main() {
    int i;
    int j;

    printf("Enter the number of vertices graph contains.\n");
    scanf("%d", &no_of_vertices);

    printf("\nEnter the Adjecency Matrix of the graph.\n");

    for(i = 0; i < no_of_vertices; i++) {
        for(j = 0; j < no_of_vertices; j++) {
            scanf("%d", &adjecency_matrix[i][j]);
        }
    }
    for(i = 0; i < no_of_vertices; i++) {
        visited[i] = 0;
    }

    DFS(0);
}

void DFS(int i) {
    int j;
    printf("\n%d", i);

    visited[i] = 1;

    for(j = 0; j < no_of_vertices; j++) {
        if(!visited[j] && adjecency_matrix[i][j] == 1) {
            DFS(j);
        }
    }
}
