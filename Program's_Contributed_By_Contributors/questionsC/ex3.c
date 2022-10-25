/* Gabriel Alves
 * Exercise lexical analysis
 * */

#include <stdio.h>

void testIf(int num1,int num2) {
	if (num1 < num2) {
		printf("Test if true\n");
	}
	else if (num1 > num2) {
		printf("Test if false");
	}
	else {
		printf("Test else true\n");
	}
return;
}

void testSwitch(int num1){
	switch(num1){
		case 1:
			printf("Number verification 1, test switch\n");
			break;
		case 2:
			printf("Number verification 2\n");
			break;
	}
	return;
}

void testLoops(int num1, int num2){
	while(num1 < num2){
		num1++;
		printf("While - Number: %d\n",num1);
		
		if (num1 * 3 == num2){
    	break;
    }
		if (num1 > 3 && num1 < 6){
			printf("Number greater than 3 and less than 6\t");

			continue;
		}
	}

	printf("-----------\n");
	for(int i = 0; i<num1; i++){
		printf("For - number: %d\n", i);
	}

	printf("-----------\n");
	do {
		printf("Do While - number: %d\n", num1);
		num1++;
	} while(num1 <= num2 * 2);

}

void funcDiv(void){
	printf("-=-=-=-=-=-=-=-=-");
	printf("-------DIV-------");
	printf("-=-=-=-=-=-=-=-=-");
}

int main(int argc, char* argv[])
{
	int num_simbolic1 = 1, var_verif = 0;
	float num_simbolic2 = 8;

	while(1){
		printf("\nWhich test will you take? 1- IF, 2- Switch, 3- Loops or 0- Exit ");
		scanf("%d", & var_verif);
		if (var_verif == 1){
			testIf(num_simbolic1, num_simbolic2);
			funcDiv();
		} if (var_verif == 2){
			testSwitch(num_simbolic1);
			funcDiv();
		} if (var_verif == 3){
			testLoops(num_simbolic1, num_simbolic2);
			funcDiv();
		}	if (var_verif == 0){
			break;
		}
	}
}
