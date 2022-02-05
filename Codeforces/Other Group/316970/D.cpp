#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll int
using namespace std;

ll g[2005], n, pre[2005], minid = 1;
vector<ll> e[2005];
vector<vector<ll>> res;

bool comp(int a, int b);

int getminchild(ll n)
{
    if (e[n].size() == 1)
        return 0;
    ll minval = 1000000000, mini = 0;
    for (ll i : e[n])
        if (pre[n] != i)
        {
            if (g[i] < minval)
                mini = i, minval = g[i];
            else if(g[i] == minval && comp(i, mini))
            mini = i, minval = g[i];
        }
    return mini;
}

bool comp(int a, int b)
{
    int _a = a, _b = b;
    while (a != 0 && b != 0 && g[a] == g[b])
        a = getminchild(a), b = getminchild(b);
    if (a == 0 && b == 0)
        return 0;
    if (a == 0)
    {
        if (g[b] > g[_b])
            return 1;
        else
            return 0;
    }
    if (b == 0)
    {
        if (g[a] > g[_b])
            return 0;
        else
            return 1;
    }
    return g[_a] < g[_b];
}

bool COMP(vector<ll> v1, vector<ll> v2)
{
    int i = 0;
    while (i < v1.size() && v1[i] == v2[i])
        i++;
    if (i == v1.size())
        return 0;
    return v1[i] < v2[i];
}

vector<ll> dfs(ll n)
{
    vector<ll> v;
    vector<ll> r = {g[n]};
    for (ll i : e[n])
        if (pre[n] != i)
        {
            pre[i] = n;
            v.emplace_back(i);
        }
    sort(v.begin(), v.end(), comp);
    for (auto i : v)
    {
        vector<ll> c = dfs(i);
        for (ll j : c)
            r.emplace_back(j);
    }
    return r;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i];
        if (g[i] < g[minid])
            minid = i;
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (g[i] == g[minid])
        {
            res.emplace_back(dfs(i));
            for (int j = 1; j <= n; j++)
                pre[j] = 0;
        }
    }

    sort(res.begin(), res.end(), COMP);
    for (ll i : res[0])
        cout << i << " ";
}