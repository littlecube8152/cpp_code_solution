#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, pre[100005], ans;
vector<int> r[7];

signed main()
{
    fast;
    ifstream cin("div7.in");
    ofstream cout("div7.out");

    cin >> n;
    r[0].emplace_back(0);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        pre[i] += pre[i - 1] + a;
        r[pre[i] % 7].emplace_back(i);
    }
    for (int i = 0; i < 7; i++)
        if(!r[i].empty())
            ans = max(r[i].back() - r[i].front(), ans);
    cout << ans << '\n';
}