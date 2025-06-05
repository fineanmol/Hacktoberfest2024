// C++ program to print the pattern G 
#include <iostream> 
using namespace std; 

void pattern(int line) 
{ 
	int i, j; 
	for(i = 0; i < line; i++) 
	{ 
		for(j = 0; j < line; j++) 
		{ 
			if((j == 1 && i != 0 && i != line - 1) || 
			((i == 0 || i == line - 1) && j > 1 && 
			j < line - 2) || (i == ((line - 1) / 2) && 
			j > 2 && j < line - 1) || (j == line - 2 && 
			i != 0 && i >= ((line - 1) / 2) && i != line - 1)) 
				printf("*"); 
			else
				printf( " "); 

		} 
		printf("\n"); 
	} 
} 

// Driver code 
int main() 
{ 
	int line = 7; 
	pattern(line); 
	return 0; 
} 

// This code is contributed 
// by vt_m. 
