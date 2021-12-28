//#pragma GCC optimize("O3,unroll-loops")
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

ll n, val[2005], dis[2005], ans;
bool ismst[2005];
signed main()
{
    ifstream cin("superbull.in");
    ofstream cout("superbull.out");
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 0; i <= n; i++)
        dis[i] = 1LL << 32;
    dis[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int index = 0;
        for (int j = 1; j <= n; j++)
            if (dis[j] < dis[index] && !ismst[j])
                index = j;
        ans += dis[index];
        ismst[index] = 1;
        for (int j = 1; j <= n; j++)
            dis[j] = min(dis[j], -(val[index] ^ val[j]));
    }
    cout << -ans << '\n';
}