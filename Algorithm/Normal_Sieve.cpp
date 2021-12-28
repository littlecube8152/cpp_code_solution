#include <bits/stdc++.h>
using namespace std;

int prime[100000], index = 1;

int main()
{
    //Easy Sieve
    // | Range |  Time  |
    // |-------|--------|
    // |  1e5  |   3 ms |
    // |  1e6  |  76 ms |
    // |  1e7  | 1.5  s |

    prime[0] = 2;
    for (int i = 3; i < 1000000; i += 2)
    {
        bool isprime = true;
        for (int j = 0; prime[j] <= sqrt(i) && isprime; j++)
            if (!(i % prime[j])) isprime = false;
        if (isprime) prime[index++] = i;
    }
}