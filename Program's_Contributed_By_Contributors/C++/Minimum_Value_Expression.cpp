#include <bits/stdc++.h>
using namespace std;

// Utility method to check whether a character
// is operator or not
bool isOperator(char op)
{
return (op == '+' || op == '*');
}

// method prints minimum and maximum value
// obtainable from an expression
void printMinAndMaxValueOfExp(string exp)
{
vector<int> num;
vector<char> opr;
string tmp = "";

// store operator and numbers in different vectors
for (int i = 0; i < exp.length(); i++)
{
  if (isOperator(exp[i]))
  {
   opr.push_back(exp[i]);
   num.push_back(atoi(tmp.c_str()));
   tmp = "";
  }
  else
  {
   tmp += exp[i];
  }
}
// storing last number in vector
num.push_back(atoi(tmp.c_str()));

int len = num.size();
int minVal[len][len];
int maxVal[len][len];

// initializing minval and maxval 2D array
for (int i = 0; i < len; i++)
{
  for (int j = 0; j < len; j++)
  {
   minVal[i][j] = INT_MAX;
   maxVal[i][j] = 0;

   // initializing main diagonal by num values
   if (i == j)
    minVal[i][j] = maxVal[i][j] = num[i];
  }
}

// looping similar to matrix chain multiplication
// and updating both 2D arrays
for (int L = 2; L <= len; L++)
{
  for (int i = 0; i < len - L + 1; i++)
  {
   int j = i + L - 1;
   for (int k = i; k < j; k++)
   {
    int minTmp = 0, maxTmp = 0;

    // if current operator is '+', updating tmp
    // variable by addition
    if(opr[k] == '+')
    {
     minTmp = minVal[i][k] + minVal[k + 1][j];
     maxTmp = maxVal[i][k] + maxVal[k + 1][j];
    }

    // if current operator is '*', updating tmp
    // variable by multiplication
    else if(opr[k] == '*')
    {
     minTmp = minVal[i][k] * minVal[k + 1][j];
     maxTmp = maxVal[i][k] * maxVal[k + 1][j];
    }

    // updating array values by tmp variables
    if (minTmp < minVal[i][j])
     minVal[i][j] = minTmp;
    if (maxTmp > maxVal[i][j])
     maxVal[i][j] = maxTmp;
   }
  }
}

// last element of first row will store the result
cout << "Minimum value : " << minVal[0][len - 1]
  << ", Maximum value : " << maxVal[0][len - 1];
}

// Driver code to test above methods
int main()
{
string expression = "1+2*3+4*5";
printMinAndMaxValueOfExp(expression);
return 0;
}
