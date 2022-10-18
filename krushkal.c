#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define V 6
typedef struct GRAPH
{
    int u;
    int v;
    int w;
}graph;

int *array = NULL;

graph *take_input(int vertices, int edges)
{
    int u, v, w;
    graph *g = (graph *)malloc(sizeof(graph) * edges);
    array = (int *)malloc(sizeof(int) * vertices);

    if(g == NULL)
    {
        printf("No graph\n");
        exit(0);
    }

    if(array == NULL)
    {
        printf("No graph\n");
        exit(0);
    }

    for(int i=0;i<vertices;i++)
    {
        array[i] = i;
    }

    for(int i=0;i<edges;i++)
    {
        printf("Enter the vertex 1 of edge %d:\n", i+1);
        scanf("%d", &u);
        printf("Enter the vertex 2 of edge %d:\n", i+1);
        scanf("%d", &v);

        if(u>v)
        {
            g[i].u = v;
            g[i].v = u;
        }
        else{
            g[i].u = u;
            g[i].v = v;
        }

        printf("Enter the weight of the edge %d:\n", i+1);
        scanf("%d", &g[i].w);
    }
    printf("\n\n");

    return g;
}

void swap(graph *g1, graph *g2)
{
    graph *t;
    t = (graph *)malloc(sizeof(graph));

    if(t==NULL)
    {
        printf("No graph\n");
    }

    *t = *g1;
    *g1 = *g2;
    *g2 = *t;

    free(t);
}
void bubble_sort(int edges, graph *g)
{
    graph *t;
    t = (graph *)malloc(sizeof(graph));

    for(int i=0;i<edges-1;i++)
    {
        for(int j=0;j<edges-i-1;j++)
        {
            if(g[j].w > g[j+1].w)
            {
                swap((g+j), (g+j+1));
            }
        }
    }
}

void unionn(int a, int b, int vertices)
{
    int p = array[a];
    int q = array[b];

    for(int i=0;i<vertices;i++)
    {
        if(array[i] == p)
        {
            array[i] = q;
        }
    }
}

int find(int a, int b, int vertices)
{
    if(array[a] == array[b])
    {
        return 1;

    }
    else{
        return 0;
    }

}

int kruskals(graph *g, int edges, int vertices)
{
    int weight = 0;
    int count = 0;

    for(int i=0;i<edges;i++)
    {
        if(count == vertices-1)
        {
            break;
        }
        if(!find(g[i].u, g[i].v, vertices))
        {
            printf("Source: %d  Destination: %d  Weight: %d\n", g[i].u, g[i].v, g[i].w);
            unionn(g[i].u, g[i].v, vertices);
            weight+=g[i].w;
            count++;
        }
    }
    return weight;
}
int main()
{
    int vertices, edges, weight;
    graph *g;

    printf("Enter the number of vertices\n");
    scanf("%d", &vertices);

    printf("Enter the number of edges\n");
    scanf("%d", &edges);

    g = take_input(vertices, edges);
    bubble_sort(edges, g);
    weight = kruskals(g, edges, vertices);

    printf("Total weight of the MST is %d\n", weight);
}
