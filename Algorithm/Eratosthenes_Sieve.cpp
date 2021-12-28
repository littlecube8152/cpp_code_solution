#include <bits/stdc++.h>
#define N 1000000
using namespace std;

bitset<N> notprime = 3;
int main()
{
    //Eratosthenes Sieve
    // | Range |  Time  |
    // |-------|--------|
    // |  1e5  |   1 ms |
    // |  1e6  |  12 ms |
    // |  1e7  | 144 ms |
    // |  4e7  | 630 ms |
    // |  5e7  | 833 ms |
    // |  1e8  | 1.9  s |
    //Pre-compute all 2n except 2
    for (int i = 4; i <= N; i += 2)
        notprime[i] = 1;

    //Main Program
    for (int i = 3; i < sqrt(N); i += 2)
        if (!notprime[i])
            for (int j = i * i; j < N; j += i * 2)
                notprime[j] = 1;


}