/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll INF = 9223372036854775807;
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll N, a[100005], p[100005], sz[100005], pre[100005], ans;
const ll C = 100000;
vector<int> E[100005], s, d[100005];

void dfs(int u, int c)
{
    sz[u] = 1;
    for (int v : E[u])
        if (pre[u] != v && a[v] % c == 0)
        {
            pre[v] = u;
            dfs(v, c);
            sz[u] += sz[v];
        }
    s.emplace_back(u);
}

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= sqrt(a[i]); j++)
        {
            if (a[i] % j == 0)
            {
                d[j].emplace_back(i);
                if (j * j != a[i])
                    d[a[i] / j].emplace_back(i);
            }
        }
    }
    for (int i = 1; i <= N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }

    for (int c = 1; c <= C; c++)
    {
        for (int i : d[c])
            pre[i] = 0;
        for (int i : d[c])
            if (!pre[i] && a[i] % c == 0)
            {
                s.clear();
                dfs(i, c);
                p[c] = (p[c] + sz[i] * (sz[i] - 1)) % MOD2;

                for (int j : s)
                {
                    ll acc = 0;
                    for (int k : E[j])
                        if (a[k] % c == 0)
                        {
                            ll z = (k == pre[j] ? sz[i] - sz[j] : sz[k]);
                            p[c] = (p[c] + acc * z) % MOD2;
                            acc = (acc + z) % MOD2;
                        }
                }
            }
    }
    for (int i = C; i >= 1; i--)
        for (int j = i + i; j <= C; j += i)
            p[i] = (p[i] - p[j] + MOD2) % MOD2;
    for (int i = 1; i <= C; i++)
        ans = (ans + p[i] * i) % MOD2;
    cout << ans << '\n';
}
