#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// return a map of prime numbers(key) and terms(values)
map<int, int> primeFactors(int n)
{
    // store the prime factors. key = prime number, value = occurance
    map<int, int> mp;

    // 2 is the smallest prime number. checking if it has any prime factor 2
    while (n % 2 == 0)
    {
        mp[2]++;
        n /= 2;
    }

    // primes greater then 2
    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            mp[i]++;
            n /= i;
        }
    }

    // if n = 1, it has no more prime factors.
    // if n > 2, now n is a prime number
    if (n > 2)
        mp[n]++;

    return mp;
}

int main()
{

    // taking input
    int n;
    cin >> n;

    // recieving the prime numbers
    map<int, int> PrimeFactors = primeFactors(n);
    // showing the prime numbers
    cout << "Prime factors: ";
    for (map<int, int>::iterator it = PrimeFactors.begin(); it != PrimeFactors.end(); it++)
    {
        cout << it->first << '^' << it->second << " ";
    }
    cout << '\n';

    // number of all factors
    cout << "Number of all factors: ";
    int numberOfFactors = 1;
    map<int, int>::iterator it = PrimeFactors.begin();
    for (;;)
    {
        numberOfFactors *= it->second + 1;
        it = next(it);
        if (it == PrimeFactors.end())
            break;
    }
    cout << numberOfFactors << '\n';

    // number of prime factors
    cout << "Number of prime factors: ";
    int numberOfPrimeFactors = 0;
    for (auto p : PrimeFactors)
        numberOfPrimeFactors += p.second;
    cout << numberOfPrimeFactors << '\n';

    cout << "Sum of all factors: ";
    int sumOfFactors = 1;
    for (pair p : PrimeFactors)
    {
        sumOfFactors *= (pow(p.first, p.second + 1) - 1) / (p.first - 1);
    }
    cout << sumOfFactors << '\n';

    // sum of the prime factors
    cout << "Sum of prime factors: ";
    int sumOfPrimeFactors = 0;
    for (pair p : PrimeFactors)
    {
        sumOfPrimeFactors += p.first * p.second;
    }
    cout << sumOfPrimeFactors << '\n';

    cout << "Product of all factors: ";
    ll productFactors = pow(n, numberOfFactors / 2);
    cout << productFactors << '\n';

    cout << "Product of prime factors: ";
    ll productOfPrimeFactors = 1;
    for (auto p : PrimeFactors)
    {
        productOfPrimeFactors *= p.first * p.second;
    }
    cout << productOfPrimeFactors << '\n';

    return 0;
}
