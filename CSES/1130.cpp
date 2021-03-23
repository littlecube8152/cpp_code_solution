#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x);
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, x, y, ans;
bool match[200005], vis[200005];
vector<int> e[200005];

void dfs(int k)
{
    for (int i : e[k])
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(i);
            if (!match[i] && !match[k])
                match[i] = 1, match[k] = 1;
        }
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1);
    for (int i = 1; i <= n;i++)
        if(match[i])
            ans++;
    cout << ans / 2;
}
