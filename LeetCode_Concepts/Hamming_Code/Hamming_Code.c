#include <stdio.h>
#include <math.h>

int calculateParityBits(int m) {
    int r = 0;
    while ((1 << r) < (m + r + 1)) {
        r++;
    }
    return r;
}

void generateHammingCode(int data[], int m, int code[], int n) {
    int parityPos = 0, dataPos = 0;

    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) == 0) {
            code[i - 1] = 0; 
        } else {
            code[i - 1] = data[dataPos++];
        }
    }

    for (int i = 0; i < n; i++) {
        if (code[i] == 0) { 
            int parity = 0;
            for (int j = 1; j <= n; j++) {
                if (j & (i + 1)) {
                    parity ^= code[j - 1];
                }
            }
            code[i] = parity;
        }
    }
}

int checkHammingCode(int code[], int n) {
    int errorPos = 0;

    for (int i = 0; i < n; i++) {
        int parity = 0;
        if ((i & (i + 1)) == 0) {
            for (int j = 1; j <= n; j++) {
                if (j & (i + 1)) {
                    parity ^= code[j - 1];
                }
            }
            if (parity != 0) {
                errorPos += (i + 1);
            }
        }
    }

    return errorPos;
}

int main() {
    int m;

    printf("Enter the number of data bits: ");
    scanf("%d", &m);

    int data[m];
    printf("Enter the data bits (0 or 1): ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &data[i]);
    }

    int r = calculateParityBits(m);
    int n = m + r;

    int code[n];
    generateHammingCode(data, m, code, n);

    printf("Generated Hamming Code: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", code[i]);
    }

    code[3] ^= 1;

    int errorPos = checkHammingCode(code, n);
    if (errorPos == 0) {
        printf("\nNo error detected.\n");
    } else {
        printf("\nError detected at position: %d\n", errorPos);
        code[errorPos - 1] ^= 1;
        printf("Corrected Hamming Code: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", code[i]);
        }
        printf("\n");
    }
}





