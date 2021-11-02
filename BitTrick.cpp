#include <bits/stdc++.h>
using namespace std;
int main()
{
    /**
     * @brief Check the number is Power of 2 or not
     *
     */
    int n;
    cin >> n;
    if (n & (n - 1))
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
    /**
     * @brief Convert UpperCase to LowerCase and Viceversa
     *
     */
    char ch;
    cin >> ch;
    ch |= 1 << 5; // UpperCase to LowerCase
    std::cout << ch << std::endl;
    ch ^= 1 << 5; // LowerCase to UpperCase
    std::cout << ch << std::endl;
    /**
     * @brief Find the number of set bits in a number
     *
     */
    int n;
    cin >> n;
    std::cout << __builtin_popcount(n) << std::endl;
    /**
     * @brief Find the number which is not Repeated in the array
     *
     */
    vector<int> arr = {1, 5, 2, 1, 3, 4, 5, 8, 4, 8, 3};
    int ans = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        ans ^= arr[i];
    }
    std::cout << ans << std::endl;
    /**
     * @brief Odd Even using bits
     *
     */
    int n;
    cin >> n;
    if (n & 1)
    {
        cout << "Odd";
    }
    else
    {
        cout << "Even";
    }
    /**
     * @brief multiply by two and divide by two
     *
     */
    int n;
    cin >> n;
    cout << (n << 1) << endl; // multiply by two
    cout << (n >> 1) << endl; // divide by two
    return 0;
}