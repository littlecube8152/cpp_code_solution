#include <bits/stdc++.h>
using namespace std;
#define maxN 10000

bool np[maxN + 1];
int mu[maxN + 1], phi[maxN + 1];
vector<int> prime;
inline void build()
{
    np[0] = np[1] = 1;
    mu[1] = 1;
    phi[1] = 1;
    for (int i = 2; i <= maxN; i++)
    {
        if (!np[i])
        {
            prime.push_back(i);
            mu[i] = -1;
            phi[i] = i - 1;
        }
        for (auto j : prime)
        {
            int t = i * j;
            if (t > maxN)
                break;
            np[t] = 1;
            if (i % j == 0)
            {
                mu[t] = 0;
                phi[t] = phi[i] * j;
                break;
            }
            else
            {
                mu[t] = -mu[i];
                phi[t] = phi[i] * (j - 1);
            }
        }
    }
}