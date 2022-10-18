// C++ program to find the celebrity

#include <bits/stdc++.h>

#include <list>

using namespace std;

// Max number of persons in the party

#define N 8

// Person with 2 is celebrity

bool MATRIX[N][N] = {{0, 0, 1, 0},

					{0, 0, 1, 0},					{0, 0, 0, 0},

					{0, 0, 1, 0}};

bool knows(int a, int b)

{

	return MATRIX[a][b];

}

// The function that finds the celebrity if present

// otherwise returns a -1

int findCelebrity(int n)

{

	//the graph needs not be constructed

	//as the edges can be found by

	//using knows function

	

	// the indegree and outdegree arrays

	int indegree[n]={0},outdegree[n]={0};

	

	//query for all edges

	for(int i=0; i<n; i++)

	{

		for(int j=0; j<n; j++)

		{

			int x = knows(i,j);

			

			//set the degrees if there is an edge from i to j

			outdegree[i]+=x;

			indegree[j]+=x;

		}

	}

	

	//find a person with indegree n-1.

	//and out degree 0, that person will be the celebrity

	for(int i=0; i<n; i++)

	if(indegree[i] == n-1 && outdegree[i] == 0)

		return i;

	

	return -1;

}

// Driver code

int main()

{

	int n = 4;

	int id = findCelebrity(n);

	id == -1 ? cout << "There is not celebrity" :

			cout << "Celebrity ID =  " << id;

	return 0;

}
