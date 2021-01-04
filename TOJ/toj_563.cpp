#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

ll n, m, p[200005] = {0}, vis[200005] = {0}, c[200005];
vector<int> e[200005];

void dfs(int n)
{
    vis[n] = 1;
    ll r = 0;
    for (auto &i : e[n])
    {
        if (vis[i] == 0)
        {
            dfs(i);
            r += c[i];
        }
        else
            i = 0;
    }
    r++;
    c[n] = r;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a].emplace_back(b);
        e[b].emplace_back(a);
    }

    //DFS
    dfs(1);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll q, res = 0;
        cin >> q;
        for (auto i : e[q])
        {
            res += c[i] * c[i];
        }
        res += (n - c[q]) * (n - c[q]);
        cout << res << ' ';
    }
    cout << '\n';
}