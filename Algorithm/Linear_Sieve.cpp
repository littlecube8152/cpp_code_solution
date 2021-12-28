#include <bits/stdc++.h>
#define N 20000000
using namespace std;

bitset<N + 1> notprime = 3;
vector<int> prime;

int main()
{
    //Linear Sieve
    // | Range |  Time  |
    // |-------|--------|
    // |  1e5  |   3 ms |
    // |  1e6  |  36 ms |
    // |  1e7  | 362 ms |
    // |  2e7  | 732 ms |
    // |  1e8  | 3.8  s |
    clock_t a, b;
    a = clock();
    for (int i = 2; i <= N; i ++)
    {
        if (!notprime[i])
            prime.emplace_back(i);
        for (auto j : prime)
        {
            if (i * j > N) break;
            notprime[i * j] = 1;
            if (!(i % j)) break;
        }
    }
    b = clock();
    cout << b - a << " ms.";
}