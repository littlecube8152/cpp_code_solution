#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

const int INF = 1e9;
int T, N, vis[1000006], dp[1000006], sz[1000006];
ll ans;
vector<int> E[1000006];
map<int, ll> sub[1000006];

void dfs(int u)
{
    vis[u] = dp[u] = 1;
    sz[u] = 0;
    for (auto v : E[u])
        if (!vis[v])
        {
            dfs(v), dp[u] = max(dp[u], dp[v] + 1);
            sub[u][dp[v]]++;
            sz[u]++;
        }
    vis[u] = 0;
}

void dfans(int u)
{
    vis[u] = 1;
    for (auto v : E[u])
        if (!vis[v])
        {
            {
                auto iter = sub[u].find(dp[v]);
                iter->S--;
                if (iter->S == 0)
                    sub[u].erase(iter);
            }

            auto iter = sub[u].begin(), jter = sub[v].begin();
            ll l = sz[u], r = sz[v], p = 0;
            while (iter != sub[u].end() || jter != sub[v].end())
            {
                int i = (iter == sub[u].end() ? INF : iter->F);
                int j = (jter == sub[v].end() ? INF : jter->F);

                ans += min(l, r) * (min(i, j) - p);
                p = min(i, j);

                if (i <= j)
                {
                    l -= iter->S;
                    ++iter;
                }
                if (i >= j)
                {
                    r -= jter->S;
                    ++jter;
                }
            }

            int k = (sub[u].empty() ? 1 : sub[u].rbegin()->F + 1);
            sub[v][k]++;
            sub[u][dp[v]]++;
            dfans(v);
        }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N;
        cerr << N << '\n';
        ans = 0;
        for (int i = 1; i <= N; i++)
            E[i].clear(), sub[i].clear();
        for (int i = 2; i <= N; i++)
        {
            int j;
            cin >> j;
            E[i].emplace_back(j);
            E[j].emplace_back(i);
        }
        fill(vis + 1, vis + 1 + N, 0);
        dfs(1);
        sz[1]--;
        dfans(1);
        cout << "Case #" << t << ": " << ans << '\n';
    }
}