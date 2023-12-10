#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 10015
using namespace std;

int n, m, c[10005], dp[10005][1 << 5], from[10005][1 << 5];
bitset<10005> e[10005];
vector<int> E[10005];

void add(int a, int b)
{
    if (e[a][b] || e[b][a])
        return;
    E[a].emplace_back(b);
    E[b].emplace_back(a);
    e[a][b] = e[b][a] = 1;
}

int readint()
{
    int v = 0;
    char c;
    while(c = getchar(), isdigit(c))
        v = v * 10 + c - '0';
    return v;
}

void solve()
{
    time_t start = clock();
    n = readint();
    m = readint();
    for (int i = 1; i <= n; i++)
    {
        E[i].clear();
        e[i].reset();
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        a = readint();
        b = readint();
        c = readint();
        add(a, b);
        add(b, c);
        add(c, a);
    }
    while (clock() - start < 1.0 * CLOCKS_PER_SEC)
    {
        mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
        for (int i = 1; i <= n; i++)
            c[i] = rd() % 5;
        for (int i = 1; i <= n; i++)
        {
            fill(dp[i], dp[i] + 32, 0);
            dp[i][0] = 1;
        }
        for (int mask = 0; mask < 32; mask++)
            for (int i = 1; i <= n; i++)
                if (dp[i][mask])
                    for (int j : E[i])
                        if (!((mask >> c[j]) & 1))
                        {
                            dp[j][mask ^ (1 << c[j])] = 1;
                            from[j][mask ^ (1 << c[j])] = i;
                        }
        for (int i = 1; i <= n; i++)
            if (dp[i][31])
            {
                int u = i, mask = 31, tmp;
                for (int k = 1; k <= 5; k++)
                {
                    cout << u << " \n"[k == 5];
                    tmp = mask ^ (1 << c[u]);
                    u = from[u][mask];
                    mask = tmp;
                }
                return;
            }
    }
    cout << -1 << '\n';
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}