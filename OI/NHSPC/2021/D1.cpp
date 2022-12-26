#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
using namespace std;

int n, m, ans = 1e9, deg[25], lvl[25], ansmask;
pii edge[25];
signed main()
{
    //ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> edge[i].F >> edge[i].S >> lvl[i];
    for (int mask = 0; mask < (1 << m); mask++)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            deg[i] = 0;
        for (int i = 0; i < m; i++)
            if (mask & (1 << i))
                swap(edge[i].F, edge[i].S);
        vector<int> E[25];
        for (int i = 0; i < m; i++)
        {
            E[edge[i].F].emplace_back(edge[i].S);
            deg[edge[i].S]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (deg[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cnt++;
            for (int i : E[u])
            {
                deg[i]--;
                if (deg[i] == 0)
                    q.push(i);
            }
        }
        if (cnt == n)
        {
            int mxlvl = 0;
            for (int i = 0; i < m; i++)
                if (mask & (1 << i))
                    mxlvl = max(mxlvl, lvl[i]);
            if(mxlvl <= ans)
                ans = mxlvl, ansmask = mask;
        }
        for (int i = 0; i < m; i++)
            if (mask & (1 << i))
                swap(edge[i].F, edge[i].S);
    }
    cout << ans << " " << __builtin_popcount(ansmask) << '\n';
    for (int i = 0; i < m; i++)
            if (ansmask & (1 << i))
                cout << i + 1 << '\n';
}
/*
5 6
2 1 1
1 5 4
5 2 6
2 3 2
3 4 3
4 5 2
*/