#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, k, match[1005], ans, t = 0;
vector<int> adj[1005];
bool vis[1005];

bool bimatch(int x)
{
    for (int i : adj[x])
    {
        if (!vis[i])
        {
            vis[i] = 1;
            if (!match[i] || bimatch(match[i]))
            {
                match[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

signed main()
{
    while (cin >> n >> k)
    {
        t++;
        if (n == 0 && k == 0)
            break;


        memset(match, 0, sizeof(match));
        ans = 0;
        for (int i = 1; i <= n; i++)
            adj[i].clear();



        for (int i = 1; i <= k; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
        }
        for (int i = 1; i <= n; i++)
        {
            memset(vis, 0, sizeof(vis));
            if (bimatch(i))
                ans++;
        }
        cout << "Case #" << t << ":" << ans << '\n';
    }
}