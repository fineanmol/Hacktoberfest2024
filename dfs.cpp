#include <iostream>
using namespace std;
typedef struct gnode
{
    int vertex;
    struct gnode *next;
} gnode;

gnode *graph1[20];
int visited[20];
int parent[20];

void create_graph(int vertex, int node)
{
    gnode *temp = (gnode *)malloc(sizeof(gnode));
    temp = graph1[vertex];
    while (temp->next != NULL)
        temp = temp->next;

    gnode *x = (gnode *)malloc(sizeof(gnode));
    x->vertex = node;
    x->next = NULL;
    temp->next = x;
}
void print_graph(int vertices)
{
    gnode *temp = (gnode *)malloc(sizeof(gnode));
    for (int i = 0; i < vertices; i++)
    {
        temp = graph1[i];
        cout << i << "-> ";
        temp = temp->next;
        while (temp != NULL)
        {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
int count_edges(int vertices)
{
    gnode *temp = (gnode *)malloc(sizeof(gnode));
    int count = 0;
    for (int i = 0; i < vertices; i++)
    {
        temp = graph1[i];
        temp = temp->next;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
    }
    return count;
}
int max_outgoing(int n)
{
    gnode *temp = (gnode *)malloc(sizeof(gnode));
    int max_out[n];
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        temp = graph1[i];
        temp = temp->next;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        max_out[i] = count;
    }
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (max_out[i] > max_out[max])
            max = i;
    }
    return max;
}
void all_connections(int n)
{
    gnode *temp = (gnode *)malloc(sizeof(gnode));
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        temp = graph1[i];
        temp = temp->next;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        if (count == n - 1)
            cout << "Vertex " << i << " is having connections with all other vertices" << endl;
    }
}
int min_incomming(int n)
{
    gnode *temp = (gnode *)malloc(sizeof(gnode));
    int min_inc[n] = {0};
    for (int i = 0; i < n; i++)
    {
        temp = graph1[i];
        temp = temp->next;
        while (temp != NULL)
        {
            min_inc[temp->vertex]++;
            temp = temp->next;
        }
    }
    int min = 0;
    for (int i = 0; i < n; i++)
    {
        if (min_inc[i] < min_inc[min])
            min = i;
    }
    return min;
}

void unconnected(int n)
{
    gnode *temp = (gnode *)malloc(sizeof(gnode));
    for (int i = 0; i < n; i++)
    {
        temp = graph1[i];
        temp = temp->next;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        int min_inc[n] = {0};
        for (int j = 0; j < n; j++)
        {
            temp = graph1[j];
            temp = temp->next;
            while (temp != NULL)
            {
                min_inc[temp->vertex]++;
                temp = temp->next;
            }
        }
        if (count == 0)
        {
            if (min_inc[i] > 0)
                count = min_inc[i];
        }
        if (count == 0)
            cout << "Vertex " << i << " is unconnected" << endl;
        else
            cout << "Vertex " << i << " is connected" << endl;
    }
}

void DFS_Visit(int n, int i)
{
    visited[i] = 1;
    cout << i << " ";
    gnode *temp = (gnode *)malloc(sizeof(gnode));
    temp = graph1[i];
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            temp = temp->next;
        }
        else
        {
            int adjv = temp->next->vertex;
            if (visited[adjv] == 0)
            {
                parent[adjv] = i;
                DFS_Visit(n, adjv);
            }
            temp = temp->next;
        }
    }
}
void DFS(int n)
{
    for (int i = 0; i < 20; i++)
        visited[i] = 0;
    for (int i = 0; i < 20; i++)
        parent[i] = -1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            DFS_Visit(n, i);
    }
}
int main()
{
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    for (int i = 0; i < 20; i++)
    {
        graph1[i] = (gnode *)malloc(sizeof(gnode));
        graph1[i]->next = NULL;
    }
    create_graph(0, 2);
    create_graph(0, 4);
    create_graph(0, 1);
    create_graph(1, 3);
    create_graph(1, 6);
    create_graph(2, 4);
    create_graph(3, 4);
    create_graph(6, 2);
    print_graph(vertices);

    int count = count_edges(vertices);
    cout << "Total number of edges are: " << count << endl;

    int max = max_outgoing(vertices);
    cout << "Vertex having maximum outgoing edges is: " << max << endl;

    all_connections(vertices);

    int min = min_incomming(vertices);
    cout << "Vertex having minimum incomming edges is: " << min << endl;

    unconnected(vertices);

    cout<<"DFS Traversal:"<<endl;
    DFS(vertices);

    return 0;
}
