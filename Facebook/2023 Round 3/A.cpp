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

int T, N, M, K, vis[105], nxt[105];
vector<int> E[105], sz;

int dfs(int u)
{
    int r = vis[u] = 1;
    for (auto v : E[u])
        if (!vis[v])
            r += dfs(v);
    return r;
}

bool brute(int L, int rem = 0, int last = 0, int used = 0)
{
    if (rem == 0 && used == K)
        return true;

    if (rem == 0)
        rem = L, last = 0;
    for (int i = last; i < K; i = (vis[i] ? i + 1 : nxt[i]))
        if (!vis[i] && sz[i] <= rem)
        {
            vis[i] = 1;
            if (brute(L, rem - sz[i], i + 1, used + 1))
                return true;
            vis[i] = 0;
            if (rem == L)
                return false;
        }
    return false;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ":";

        cin >> N >> M;

        fill(vis, vis + N + 1, 0);
        for (int i = 1; i <= N; i++)
            E[i].clear();
        sz.clear();

        for (int i = 1; i <= M; i++)
        {
            int u, v;
            cin >> u >> v;
            E[u].emplace_back(v);
            E[v].emplace_back(u);
        }
        for (int i = 1; i <= N; i++)
            if (!vis[i])
                sz.emplace_back(dfs(i));
        K = sz.size();

        sort(sz.begin(), sz.end());
        nxt[K - 1] = K;
        for (int i = K - 2; i >= 0; i--)
            if (sz[i] != sz[i + 1])
                nxt[i] = i + 1;
            else
                nxt[i] = nxt[i + 1];

        for (int i = 1; i <= N; i++)
        {
            fill(vis, vis + K + 1, 0);
            if (N % i == 0 && N / i >= sz.back() && brute(N / i))
                cout << ' ' << i;
        }

        cout << '\n';
    }
}