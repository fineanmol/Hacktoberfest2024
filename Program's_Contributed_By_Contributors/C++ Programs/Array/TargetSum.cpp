#include <iostream>
#include <vector>
using namespace std;
int findTotalWays(vector<int> arr, int i, int s, int target)
{
	if (s == target && i == arr.size())
		return 1;
	if (i >= arr.size())
		return 0;
	return findTotalWays(arr, i + 1, s + arr[i], target)
		+ findTotalWays(arr, i + 1, s - arr[i], target);
}


int main()
{
	vector<int> arr = { 1, 1, 1, 1, 1 };


	int target = 3;

	cout << findTotalWays(arr, 0, 0, target) << endl;

	return 0;
}
