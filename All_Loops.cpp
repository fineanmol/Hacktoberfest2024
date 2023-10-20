#include <iostream>

int main() {
    int n;

    // Using a for loop to calculate the sum
    std::cout << "Enter a positive integer: ";
    std::cin >> n;
    
    int sum_for = 0;
    for (int i = 1; i <= n; i++) {
        sum_for += i;
    }
    std::cout << "Sum using a for loop: " << sum_for << std::endl;

    // Using a while loop to calculate the sum
    int sum_while = 0;
    int j = 1;
    while (j <= n) {
        sum_while += j;
        j++;
    }
    std::cout << "Sum using a while loop: " << sum_while << std::endl;

    // Using a do-while loop to calculate the sum
    int sum_do_while = 0;
    int k = 1;
    do {
        sum_do_while += k;
        k++;
    } while (k <= n);
    std::cout << "Sum using a do-while loop: " << sum_do_while << std::endl;

    return 0;
}
