#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int M, K, D;
bitset<20> b[16];
vector<int> v;

void brute(int pos, int cnt)
{
    if (cnt == 16)
    {
        cout << '\n';
        cout << 16 << '\n';
        for (int i = 0; i < 16; i++)
            cout << b[i] << '\n';
        cout << flush;
        //exit(0);
    }
    for (auto i = pos; i < v.size(); i++)
    {
        bool can = 1;
        for (int j = 0; j < cnt; j++)
            if (__builtin_popcount(v[i] & b[j].to_ulong()) > D)
                can = 0;
        if (can)
        {
            b[cnt] = v[i];
            brute(i + 1, cnt + 1);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    M = 20, K = 12, D = 7;

    for (int i = 0; i < (1 << 20); i++)
    {
        if (__builtin_popcount(i) == K)
            v.emplace_back(i);
    }
    brute(0, 0);
}
