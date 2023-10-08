#include <bits/stdc++.h>
#define ll long long
#define pii pair<short, short>
#define F first
#define S second
using namespace std;

int n, m, c[10005], vis[10005];
pii p[10005];
vector<int> E[10005], ord;

bool find_cyc(int u, int a, int b, int r)
{
    if(u == r)
        return 1;
    vis[u] = 1;
    for (auto v : E[u])
        if (c[v] == a && !vis[v])
        {
            if (find_cyc(v, b, a, r))
                return 1;
        }
    return 0;
}

void flip(int u, int a, int b)
{
    vis[u] = 1;
    c[u] = a;
    for (auto v : E[u])
        if (!vis[v] && c[v] == a)
            flip(v, b, a);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].F >> p[i].S;
        p[i].S = -p[i].S;
        ord.emplace_back(i);
    }
    sort(ord.begin(), ord.end(), [&](int i, int j)
         { return p[i] < p[j]; });
    for (int i = 1; i <= n; i++)
        p[i].S = -p[i].S;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    reverse(ord.begin(), ord.end());
    for (int i : ord)
    {
        vector<int> v;
        for (int j : E[i])
            if (c[j])
                v.emplace_back(j);
        assert(v.size() <= 4);
        sort(v.begin(), v.end(), [&](int a, int b)
             {   
                if(a == b) return false; 
                if(p[a].F == p[i].F) return false; 
                if(p[b].F == p[i].F) return true; 
                return p[a].S > p[b].S; });
        vector<int> co(5, 0);
        for (int j : v)
            co[c[j]]++;
        for (int j = 1; j <= 4; j++)
            if (!co[j])
                c[i] = j;
        if (c[i])
            continue;
        for (int i = 1; i <= n; i++)
            vis[i] = 0;
        bool flag = find_cyc(v[0], c[v[2]], c[v[0]], v[2]);
        if (flag)
        {
            int C = c[v[1]];
            for (int i = 1; i <= n; i++)
                vis[i] = 0;
            flip(v[1], c[v[3]], c[v[1]]);
            c[i] = C;
        }
        else
        {
            int C = c[v[0]];
            for (int i = 1; i <= n; i++)
                vis[i] = 0;
            flip(v[0], c[v[2]], c[v[0]]);
            c[i] = C;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << c[i] << '\n';
}