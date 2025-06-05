#include<bits/stdc++.h>

using namespace std;

void setZeroes(vector < vector < int >> & matrix) {
  int rows = matrix.size(), cols = matrix[0].size();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 0) {

        int ind = i - 1;
        while (ind >= 0) {
          if (matrix[ind][j] != 0) {
            matrix[ind][j] = -1;
          }
          ind--;
        }
        ind = i + 1;
        while (ind < rows) {
          if (matrix[ind][j] != 0) {
            matrix[ind][j] = -1;
          }
          ind++;
        }
        ind = j - 1;
        while (ind >= 0) {
          if (matrix[i][ind] != 0) {
            matrix[i][ind] = -1;

          }
          ind--;
        }
        ind = j + 1;
        while (ind < cols) {
          if (matrix[i][ind] != 0) {
            matrix[i][ind] = -1;

          }
          ind++;
        }
      }
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] <= 0) {
        matrix[i][j] = 0;
      }
    }
  }

}

int main() {
  vector < vector < int >> arr;
  arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  setZeroes(arr);
  cout << "The Final Matrix is " << endl;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}
