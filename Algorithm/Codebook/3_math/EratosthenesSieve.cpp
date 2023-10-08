#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Eseive // O(N log log N / 6)
{
    int N;
    bitset<100000005> notprime;
    void calc(int k);
    void seive()
    {
        auto id = [&](int k)
        { return k / 6 * 2 - (k % 6 == 1); };

        calc(2), calc(3);
        for (int i = 5; i <= N; i += (i % 6 == 1 ? 4 : 2))
        {
            if (!notprime[id(i)])
                calc(i);
            for (int j = i; i * j <= N; j += (j % 6 == 1 ? 4 : 2))
                notprime[id(i * j)] = 1;
        }
    }
};