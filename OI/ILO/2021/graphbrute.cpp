#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

signed main()
{
    int n, m, k;
    cin >> n >> k;
    vector<pii> v;
    m = n * (n - 1) / 2;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            v.emplace_back(make_pair(i, j));
    for (ll mask = 0; mask < (1 << m); mask++)
    {
        if (__builtin_popcount(mask) < k)
            continue;
        int deg[30] = {};
        for (int i = 0; i < m; i++)
            if ((mask >> i) & 1)
                deg[v[i].F]++, deg[v[i].S]++;
        bool valid = true;
        for (int i = 0; i < m; i++)
            if ((mask >> i) & 1)
                if (__gcd(deg[v[i].F], deg[v[i].S]) != 1)
                    valid = false;
        if (valid)
        {
            cout << __builtin_popcount(mask) << '\n';
            for (int i = 0; i < m; i++)
                if ((mask >> i) & 1)
                    cout << v[i].F << " " << v[i].S << '\n';
            cout << '\n';
        }
    }
}