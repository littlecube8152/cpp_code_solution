/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
// #define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int P = 30;
int N, Q, pre[250005], vis[250005], w[250005], ans[250005], color[250005];
bool sol = 1;
vector<pii> E[250005], G[250005];

int coloring(int u, int r, int i)
{
    vis[u] = r;
    int odd = w[u];
    for (auto [v, cc] : G[u])
    {
        int c = (cc >> i) & 1;
        if (!vis[v])
        {
            color[v] = color[u] ^ c;
            odd ^= coloring(v, r, i);
        }
        else if (color[u] ^ color[v] != c)
            sol = 0;
    }
    return odd;
}

signed main()
{
    fast;
    cin >> N >> Q;
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(pii(v, i));
        E[v].emplace_back(pii(u, i));
    }

    for (int i = 1; i <= N; i++)
        w[i] = E[i].size() & 1;
    for (int i = 1; i <= Q; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        G[u].emplace_back(pii(v, x));
        G[v].emplace_back(pii(u, x));
    }
    for (int j = 0; j < P; j++)
    {
        int inv = 0, sum = 0;
        for (int i = 1; i <= N; i++)
            vis[i] = color[i] = 0;
        for (int i = 1; i <= N; i++)
            if (!vis[i])
            {
                if (coloring(i, i, j) && i != 1)
                    inv = i;
            }
        for (int i = 1; i <= N; i++)
            sum ^= w[i] * color[i];
        if (sum && inv)
            for (int i = 1; i <= N; i++)
                if (vis[i] == inv)
                    color[i] ^= 1;
        for (int i = 1; i <= N; i++)
            if (color[i])
                for (auto [_, k] : E[i])
                    ans[k] ^= (1 << j);
    }
    if (!sol)
        cout << "No\n";
    else
    {
        cout << "Yes\n";
        for (int i = 1; i < N; i++)
            cout << ans[i] << " \n"[i == N - 1];
    }
}
