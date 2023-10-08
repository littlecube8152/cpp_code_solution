#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, q, V, is[505][505], has[505][505];
map<string, int> mp;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        int u = mp[a], v = mp[c];
        if (u == 0)
            u = mp[a] = ++V;
        if (v == 0)
            v = mp[c] = ++V;
        if (b == "is-a")
            is[u][v] = 1;
        else
            has[u][v] = 1;
    }

    for (int i = 1; i <= V; i++)
        is[i][i] = 1;

    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                is[i][j] |= is[i][k] && is[k][j];

    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
            {
                has[i][j] |= has[i][k] && (is[k][j] || has[k][j]);
                has[i][j] |= is[i][k] && has[k][j];
            }

    for (int i = 1; i <= q; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        cout << "Query " << i << ": ";
        if (b == "is-a")
            cout << (is[mp[a]][mp[c]] ? "true\n" : "false\n");
        else
            cout << (has[mp[a]][mp[c]] ? "true\n" : "false\n");
    }
}