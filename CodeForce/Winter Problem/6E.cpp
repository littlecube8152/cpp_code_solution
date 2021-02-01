#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, a[200005], r[200005], vis[200005] = {0};
vector<ll> p[200005];

ll gcd(ll a, ll b)
{
    if (a == 0 || b == 0)
        return max(a, b);
    else
    {
        while (a != 0)
        {
            b %= a;
            swap(a, b);
        }
        return b;
    }
}

void dfs(ll k, ll _gcd, ll _max)
{
    vis[k] = 1;
    r[k] = max(1LL, max(gcd(0, _gcd), gcd(_max, a[k])));
    for (auto i : p[k])
        if (!vis[i])
            dfs(i, max(1LL, gcd(_gcd, a[k])), max(1LL, r[k]));
}

int main()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        p[x].emplace_back(y);
        p[y].emplace_back(x);
    }
    dfs(1, a[1], a[1]);
    for (ll i = 1; i <= n; i++)
        cout << r[i] << " ";
}