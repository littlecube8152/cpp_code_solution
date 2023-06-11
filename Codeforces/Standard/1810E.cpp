/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int dsu[200005], vis[200005], a[200005], rk[200005];
vector<int> E[200005];
priority_queue<pii, vector<pii>, greater<pii>> pq[200005];

int find(int k)
{
    return dsu[k] == k ? k : dsu[k] = find(dsu[k]);
}

bool merge(int i, int j)
{
    i = find(i), j = find(j);
    if (i == j)
        return 0;
    dsu[i] = j;
    rk[j] += rk[i];
    if (pq[i].size() > pq[j].size())
        pq[i].swap(pq[j]);
    while (!pq[i].empty())
    {
        auto top = pq[i].top();
        pq[i].pop();
        pq[j].push(top);
    }

    return 1;
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, cnt;
        cin >> n >> m;
        cnt = n;
        for (int i = 1; i <= n; i++)
        {
            dsu[i] = i;
            rk[i] = 1;
            vis[i] = 0;
            cin >> a[i];
            E[i].clear();
            while (!pq[i].empty())
                pq[i].pop();
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            E[u].emplace_back(v);
            E[v].emplace_back(u);
        }

        if (n == 1)
        {
            cout << (a[1] == 0 ? "YES\n" : "NO\n");
            continue;
        }

        for (int i = 1; i <= n; i++)
            if (!vis[i] && a[i] == 0)
            {
                for (auto v : E[i])
                    pq[find(i)].push(pii(a[v], v));
                while (!pq[find(i)].empty())
                {
                    auto [_, u] = pq[find(i)].top();
                    pq[find(i)].pop();
                    if (find(i) == find(u))
                        continue;
                    if (rk[find(i)] >= a[u])
                    {
                        vis[u] = 1;
                        merge(i, u);
                        cnt--;
                        for (auto v : E[u])
                            pq[find(i)].push(pii(a[v], v));
                    }
                    else
                    {
                        pq[find(i)].push(pii(a[u], u));
                        break;
                    }
                }
            }
        if (cnt == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
