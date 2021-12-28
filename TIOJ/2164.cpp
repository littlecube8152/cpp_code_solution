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

struct point
{
    ll x, y, z;
    ll operator-(point p)
    {
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z);
    }
};

ll n, dis[5005], ans;
point p[5005];
bool intree[5005];

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y >> p[i].z;
    for (int i = 0; i <= n; i++)
        dis[i] = 1e15;
    dis[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int index = 0;
        for (int j = 1; j <= n; j++)
            if (!intree[j] && dis[j] < dis[index])
                index = j;
        ans += dis[index];
        intree[index] = 1;
        for (int j = 1; j <= n; j++)
            dis[j] = min(dis[j], p[index] - p[j]);
    }
    cout << ans << '\n';
}