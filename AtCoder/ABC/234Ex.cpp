/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;

#define LOCAL

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> val)
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

gp_hash_table<ll, int, custom_hash> mp;
ll n, k, b, idx = 0;
pll p[200005];
vector<int> v[200005];
vector<pii> ans;

const ll base = 2000000000;

ll hh(pll p)
{
    return p.F / b * base + p.S / b;
}

signed main()
{
    fast;
    cin >> n >> k;
    b = ceil(k / sqrtl(2));

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].F >> p[i].S;
        if (!mp[hh(p[i])])
            mp[hh(p[i])] = ++idx;
        v[mp[hh(p[i])]].emplace_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int dx = 0; dx <= 2; dx++)
            for (int dy = -2; dy <= 2; dy++)
            {
                ll hash = hh({p[i].F + dx * b, p[i].S + dy * b});
                if (mp[hash])
                    for (int j : v[mp[hash]])
                        if (i != j)
                            if ((p[i].F - p[j].F) * (p[i].F - p[j].F) + (p[i].S - p[j].S) * (p[i].S - p[j].S) <= k * k)
                                ans.emplace_back(pll{min(i, j), max(i, j)});
            }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << '\n';
    for (pii p : ans)
        cout << p.F << " " << p.S << '\n';
}
