/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Since the day I applied ternary search on a non-convex function, everything was different.
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

ll safefloor(ll p, ll q)
{
    if(p >= 0)
        return p / q;
    else
        return (p + 1) / q - 1;
}

ll n, d, b, a[100005], c[100005], p, q;
ll l[100005], r[100005];

pll check(ll m)
{
    // cerr << "check " << m << '\n';
    for (int i = 1; i <= n; i++)
        c[i] = a[i];
    if (m < 0)
    {
        for (int i = 1; i <= p; i++)
        {
            ll mv = c[i];
            c[i] -= mv;
            c[l[i]] += mv;
        }
        for (int i = p + 1; i <= n; i++)
            if (l[i] <= p)
            {
                ll mv = min(-m, c[i]);
                c[i] -= mv;
                m += mv;
                c[l[i]] += mv;
            }
        for (int i = n; i > p; i--)
        {
            ll mv = c[i];
            c[i] -= mv;
            c[r[i]] += mv;
        }
    }
    else
    {
        for (int i = n; i > p; i--)
        {
            ll mv = c[i];
            c[i] -= mv;
            c[r[i]] += mv;
        }
        for (int i = p; i >= 1; i--)
            if (r[i] > p)
            {
                ll mv = min(m, c[i]);
                c[i] -= mv;
                m -= mv;
                c[r[i]] += mv;
            }
        for (int i = 1; i <= p; i++)
        {
            ll mv = c[i];
            c[i] -= mv;
            c[l[i]] += mv;
        }
    }

    int x1 = 0, x2 = 0;
    ll pre = 0;
    for (int i = 1; i <= p; i++)
    {
        if (c[i] >= b)
            c[i] -= b;
        else
            x1++;
        if (i + 1 <= p)
            c[i + 1] += c[i];
    }
    for (int i = n; i > p; i--)
    {
        if (c[i] >= b)
            c[i] -= b;
        else
            x2++;
        if (i - 1 > p)
            c[i - 1] += c[i];
    }
    // cerr << x1 << ' ' << x2 << '\n';
    return pll(x1, x2);
}

signed main()
{
    fast;
    cin >> n >> d >> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    q = n / 2, p = n - q;

    for (int i = 1; i <= n; i++)
    {
        int L = i, R = n;
        while (L < R)
        {
            int mid = (L + R + 1) / 2;
            if ((mid - i - 1) / d + 1 <= n - mid + 1)
                L = mid;
            else
                R = mid - 1;
        }
        r[i] = L;
    }
    for (int i = 1; i <= n; i++)
    {
        int L = 1, R = i;
        while (L < R)
        {
            int mid = (L + R) / 2;
            if ((i - mid - 1) / d + 1 <= mid)
                R = mid;
            else
                L = mid + 1;
        }
        l[i] = L;
    }

    ll L = -n * b, R = n * b;
    while(L < R)
    {
        ll mid = safefloor(L + R, 2);
        auto [x1, x2] = check(mid);
        if(x1 < x2)
            L = mid + 1;
        else
            R = mid;
    }
    auto [x1, x2] = check(L);
    cout << max(x1, x2) << '\n';
}
