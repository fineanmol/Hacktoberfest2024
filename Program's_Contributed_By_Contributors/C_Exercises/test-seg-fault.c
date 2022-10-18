#include <stdio.h>

int main()
{
	char * p;
	int var=-1;
	int i;

	/* Printing all memory we can read */
	p = (char *) &var;
	/* No stopping condition. The OS will stop us */
	for(i=0;; i++) {
		printf("(%i) %02hhX\n", i, p[i]);
		/*
		 * The next statement also tries to write a zero
		 * starting from &var. Try to uncomment and explain ...
		 */
		p[i] = 0; 
	}
}
