// Travelling salesman problem solution
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Graph
{
    int **matrix;
    int stpt, endpt, cost;

public:
    int r, c;
    vector<int> cost_vector; // to store costs
    void get_matrix()
    {
        cout << "No.of rows ";
        cin >> r;
        cout << "No.of columns ";
        cin >> c;
    }
    void set_matrix()
    {
        matrix = new int *[r];
        for (int i = 0; i < r; i++)
        {
            matrix[i] = new int[c];
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    void get_data()
    {
        cout << "Starting point ";
        cin >> stpt;
        cout << "Ending point ";
        cin >> endpt;
        cout << "Cost ";
        cin >> cost;
        matrix[stpt][endpt] = cost;
    }
    void put_data()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void nearest_neighbor(int city)
    {
        // parameter is source city
        int *visited = new int[r]{0};
        // int visited[3] = {0};
        int value = 1e5;
        int j, index, cost = 0, k = city, flag = 0; // flag - to check if all cities are visited
        string s = to_string(city + 1);             // to store paths
        // for cities
        // k-rows , j-columns
        while (visited[city] < 2)
        {
            visited[k]++;
            flag++;
            for (j = 0; j < r; j++)
            {
                if (k != j && visited[j] == 0 && matrix[k][j] < value)
                {
                    value = matrix[k][j];
                    index = j;
                }
                // if all cities are visited once
                else if (flag == r)
                {
                    value = matrix[k][0];
                    index = city;
                    visited[index]++;
                }
            }
            cost = cost + matrix[k][index];
            k = index;
            s.append(" -> " + to_string(k + 1));
            value = 1e5;
        }
        cout << "Path -> " << s << "   :   Cost = " << cost << endl;
        cost_vector.push_back(cost);
    }
};

int main()
{
    Graph g;
    char c;
    int smallest;
    g.get_matrix();
    g.set_matrix();
    do
    {
        g.get_data();
        cout << "Do you want to continue? y/n ";
        cin >> c;
    } while (c == 'y');
    g.put_data();
    for (int i = 0; i < g.r; i++)
    {
        g.nearest_neighbor(i);
    }
    smallest = g.cost_vector.front();
    for (int i = 0; i < g.cost_vector.size(); i++)
    {
        if (g.cost_vector[i] < smallest)
        {
            smallest = g.cost_vector[i];
        }
    }
    cout << "Optimal cost : " << smallest;
}
