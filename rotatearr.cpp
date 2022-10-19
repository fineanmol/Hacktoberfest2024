#include <iostream>
using namespace std;



void rotate(int *input, int d, int n){
        // copy the first d element in temp array
    int temp[d];
    for(int i = 0; i < d; i++) {
        temp[i] = input[i];
    }
    
    // Now shift our input array left by d position
    for(int i = d; i < n; i++) {
        input[i-d] = input[i];
    }
    
    // copy the first d elements from temp array to input array
    int k = 0;
    for(int i = n-d; i < n; i++) {
        input[i] = temp[k];
        k++;
    }
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}