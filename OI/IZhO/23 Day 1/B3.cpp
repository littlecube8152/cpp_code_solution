#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, a[500005], b[500005], pa[500005], pb[500005], vis[500005], deg[500005], bit[500005], ans[500005];
vector<int> E[500005];

void getchain(int *s)
{
    for (int i = 1; i <= n; i++)
        deg[i] = 0, E[i].clear();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
        deg[u]++, deg[v]++;
    }
    int u = min_element(deg + 1, deg + 1 + n) - deg;
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        s[i] = u;
        vis[u] = 1;
        for (auto v : E[u])
            if (!vis[v])
            {
                u = v;
                break;
            }
    }
}

void modify(int pos, int val)
{
    for (; pos <= n; pos += (pos & -pos))
        bit[pos] += val;
}

int query(int pos)
{
    int res = 0;
    for (; pos; pos -= (pos & -pos))
        res += bit[pos];
    return res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    getchain(a);
    getchain(b);
    for (int i = 1; i <= n; i++)
        pa[a[i]] = i,
        pb[b[i]] = i;
    auto dothings = [&]()
    {
        for (int i = 1; i <= n; i++)
            bit[a[i]] = 0;
        for (int i = 1; i <= n; i++)
        {
            ans[a[i]] += query(pb[a[i]]);
            if (pa[a[i]] > pb[a[i]])
                modify(pb[a[i]], 1);
        }
    };
    dothings();
    reverse(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        pa[i] = (n + 1) - pa[i];
    dothings();
    for (int i = 1; i <= n; i++)
        pb[i] = (n + 1) - pb[i];
    dothings();
    reverse(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        pa[i] = (n + 1) - pa[i];
    dothings();
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}