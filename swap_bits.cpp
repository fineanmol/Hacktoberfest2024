#include <bits/stdc++.h>
using namespace std;

void printBinary(unsigned int n) {
    for(int i=10; i>=0; i--) {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}


// number= 00000011100 
// set1 = 00000000000
// set2 = 00000000011
// Xor = 00000000011
// Xor = 00000011011
// Result = 00000000111

int swapBits(unsigned int x, unsigned int p1,
             unsigned int p2, unsigned int n)
{
    /* Move all bits of first set to rightmost side */
    unsigned int set1 = (x >> p1) & ((1U << n) - 1); // checking if it is 0s, 1s, at the positions and storing
    cout << "set1 = ";
    printBinary(set1);
    /* Move all bits of second set to rightmost side */
    unsigned int set2 = (x >> p2) & ((1U << n) - 1); // checking if it is 0s, 1s, at the positions and storing
    cout << "set2 = ";
    printBinary(set2);

    /* Xor the two sets */
    unsigned int Xor = (set1 ^ set2); 
    cout << "Xor = ";
     printBinary(Xor);

    /* Put the Xor bits back to their original positions */
    Xor = (Xor << p1) | (Xor << p2);
    cout << "Xor = ";
    printBinary(Xor);

    /* Xor the 'Xor' with the original number so that the
    two sets are swapped */
    unsigned int result = x ^ Xor;

    return result;
}

int swapBits1(int n, int p1, int p2, int x) {
    int set1 = (n >> p1) & (1U << x) - 1;
    int set2 = (n >> p2) & (1U << x) - 1;
    int Xor = set1 ^ set2;
    Xor = (Xor << p1) | (Xor << p2);
    return Xor ^ n;
}


int main() {
    cout << "number= ";
    printBinary(28);
    unsigned int res = swapBits(28, 0, 3, 2); // number, first ith bit, second ith bit, no of bits to be swapped
    cout << "Result = ";
    printBinary(res);
    cout << endl;
    printBinary((1U << 2) - 1);
    cout << endl;
    return 0;
}

// 1) Move all bits of the first set to the rightmost side
//    set1 =  (x >> p1) & ((1U << n) - 1)
// Here the expression (1U << n) - 1 gives a number that //basically 1U<<2 is 100(4) then (1U<<2) - 1 is 011(3)
// contains last n bits set and other bits as 0. We do &
// with this expression so that bits other than the last
// n bits become 0.
// 2) Move all bits of second set to rightmost side
//    set2 =  (x >> p2) & ((1U << n) - 1)
// 3) XOR the two sets of bits
//    xor = (set1 ^ set2)
// 4) Put the xor bits back to their original positions.
//    xor = (xor << p1) | (xor << p2)
// 5) Finally, XOR the xor with original number so
//    that the two sets are swapped.
//    result = x ^ xor
