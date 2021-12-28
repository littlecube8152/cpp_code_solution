#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int t, a, b, mx;
queue<pii> q;
bool vis[5000005][2];
signed main()
{
    fast;

    ifstream cin;
    cin.open("feast.in");
    ofstream cout;
    cout.open("feast.out");
    cin >> t >> a >> b;

    q.push(make_pair(0, 0));
    vis[0][0] = 1;

    while (!q.empty())
    {
        pii k = q.front();
        q.pop();
        mx = max(mx, k.F);

        if (!vis[k.F / 2][1] && k.S == 0)
        {
            q.push(make_pair(k.F / 2, 1));
            vis[k.F / 2][1] = 1;
        }
        if (!vis[k.F + a][k.S] && k.F + a <= t)
        {
            q.push(make_pair(k.F + a, k.S));
            vis[k.F + a][k.S] = 1;
        }
        if (!vis[k.F + b][k.S] && k.F + b <= t)
        {
            q.push(make_pair(k.F + b, k.S));
            vis[k.F + b][k.S] = 1;
        }
    }
    cout << mx << '\n';
}