#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int e[1005][1005], n, m, dsu[1005];
int vis[1005], viscount;
queue<int> q;
map<int, int> p;

void solve()
{
    cin >> n >> m;
    p.clear();
    memset(vis, 0, 1005);
    viscount = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            if (i != j)
                e[i][j] = c - 96;
        }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            if (e[i][j] == e[j][i])
            {
                cout << "YES\n";
                for (int k = 1; k <= m + 1; k++)
                    cout << (k % 2 ? i : j) << " ";
                cout << '\n';
                return;
            }
            else if (m % 2)
            {
                cout << "YES\n";
                for (int k = 1; k <= m + 1; k++)
                    cout << (k % 2 ? i : j) << " ";
                cout << '\n';
                return;
            }
            else if (m % 4 == 0)
            {
                if (p[i])
                {
                    cout << "YES\n";
                    for (int k = 1; k <= m + 1; k++)
                        cout << (k % 2 ? i : (k % 4 ? j : p[i])) << " ";
                    cout << '\n';
                    return;
                }
                if (p[j])
                {
                    cout << "YES\n";
                    for (int k = 1; k <= m + 1; k++)
                        cout << (k % 2 ? j : (k % 4 ? i : p[j])) << " ";
                    cout << '\n';
                    return;
                }
                p[i] = j, p[j] = i;
            }
        }
    cout << "NO\n";
}
signed main()
{

    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}