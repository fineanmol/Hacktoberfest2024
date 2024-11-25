#include <stdio.h>

int main() {
	float f = 0.2;
	char * p_chr;
	int i;
	
	printf("Variable f of type float\n");
	printf("[%p]: %f, sizeof(f)=%d, sizeof(&f)=%d\n",
	       &f, f, (int)sizeof(f), (int)sizeof(&f));

	printf("\nPrinting the same content as array of bytes\n");
	p_chr = (char *)&f;
	for(i=0; i<sizeof(f); i++) {
		printf("[%p]: %02hhX\n", &p_chr[i], p_chr[i]);
	}
	/* Next code modifies the representation of f */
	/* p_chr[0] = 0;
	p_chr[1] = 0;
	printf("Variable f after least significant 2 bytes are zeroed: %f\n", f); */
}
