#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n1, m1, n2, m2;
  cout << "enter the matrix dimensions:";
  cin >> n1 >> m1 >> n2 >> m2;
  int matrix1[n1][m1], matrix2[n2][m2];
  if (m1 != n2)
  {
    cout << "matrix multiplication not possible here! \n";
    return 0;
  }
  int finalMatrix[n1][m2];
  cout << "enter the first matrix:\n";
  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < m1; j++)
    {
      cin >> matrix1[i][j];
    }
  }

  cout << "enter the second matrix:\n";
  for (int i = 0; i < n2; i++)
  {
    for (int j = 0; j < m2; j++)
    {
      cin >> matrix2[i][j];
    }
  }
  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < m2; j++)
    {
      int value = 0;
      for (int k = 0; k < m1; k++)
      {
        value += matrix1[i][k] * matrix2[k][j];
      }
      finalMatrix[i][j] = value;
    }
  }
  cout << endl
       << endl;
  cout << "Resultant matrix is:\n";
  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < m2; j++)
    {
      cout << finalMatrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}