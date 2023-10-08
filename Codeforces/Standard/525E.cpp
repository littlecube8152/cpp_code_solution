/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, k;
ll s, fac[30], a[30];
vector<ll> l[30], r[30];

ll findsum(vector<ll> a, vector<ll> b)
{
    ll ans = 0;
    int l = 0, r = 0;
    for (int i = 0; i < a.size(); i++)
    {
        while (l < b.size() && a[i] + b[l] < s)
            l++;
        while (r < b.size() && a[i] + b[r] <= s)
            r++;
        ans += r - l;
    }
    return ans;
}

void brute(int i, int j, int l, ll sum, vector<ll> *v)
{
    if (sum > s)
        return;
    if (i >= l)
        v[j].emplace_back(sum);
    else
    {
        brute(i + 1, j, l, sum, v);
        brute(i + 1, j, l, sum + a[i], v);
        if (a[i] <= 20 && j < k)
            brute(i + 1, j + 1, l, sum + fac[a[i]], v);
    }
}

signed main()
{
    fast;
    fac[0] = 1;
    for (int i = 1; i <= 20; i++)
        fac[i] = fac[i - 1] * i;

    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    brute(1, 0, (n + 1) / 2, 0, l);
    brute((n + 1) / 2, 0, n + 1, 0, r);
    for (int i = 0; i <= k; i++)
        sort(l[i].begin(), l[i].end(), greater<>()),
            sort(r[i].begin(), r[i].end());
    ll ans = 0;
    for (int i = 0; i <= k; i++)
        for (int j = 0; i + j <= k; j++)
            ans += findsum(l[i], r[j]);
    cout << ans << '\n';
}
