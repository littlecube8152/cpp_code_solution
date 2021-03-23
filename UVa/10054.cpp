#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, adj[55][55], deg[55], odd;
stack<pii> st;

signed main()
{
    fast;
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        adj[x][y]++, adj[y][x]++;
        deg[x]++, deg[y]++;
    }
    for (int i = 1; i <= 50; i++)
        if (deg[i] % 2)
            odd++;
    if (odd != 0 && odd != 2)
    {
        cout << "some beads may be lost\n";
        return 0;
    }

    for (int i = 1; i <= 50; i++)
        if (odd % 2)
        {
            if (deg[i] % 2)
            {
                dfs(i);
                break;
            }
        }
        else if (deg[i] > 0)
        {
            dfs(i);
            break;
        }
}