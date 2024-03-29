/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll n, a[200005], cur, l[200005], r[200005];
pll dec[200005];
map<int, ll> inc[200005];

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1, j = 0, k = 1; i <= n; i++)
    {
        if (j - i + 1 <= a[j])
            j = 0;
        while (k <= n && k - i + 1 <= a[k])
            k++;
        if (j == 0)
        {
            j = k;
            k = min(k + 1LL, n + 1);
            while (k <= n && k - i + 1 <= a[k])
                k++;
        }
        cur += j - i;
        inc[j][j - i + 1] = k - j;
        r[i] = j;
    }

    for (int i = 1; i <= n + 1; i++)
        l[i] = n;
    for (int i = n; i >= 1; i--)
        l[r[i] - 1] = i;
    for (int i = n; i >= 1; i--)
        l[i] = min(l[i + 1], l[i]);
    for (int i = 1; i <= n; i++)
        r[i] += r[i - 1];
        
    for (int i = 1; i <= n; i++)
    {
        ll acc = 0;
        inc[i][0] = 0;
        for (auto &[j, k] : inc[i])
        {
            acc += k;
            k = acc;
        }
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int p, x;
        cin >> p >> x;
        if (a[p] <= x)
            cout << cur + prev(inc[p].upper_bound(x))->S << '\n';
        else
        {
            ll ans = cur;
            if (l[p] <= p - x + 1)
                ans += (p - x + 1 - l[p]) * p - (r[p - x] - r[l[p] - 1]);
            cout << ans << '\n';
        }
    }
}
