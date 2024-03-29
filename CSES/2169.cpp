/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
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

int n, sup[200005], sub[200005];
tree<pii, null_type, greater<pii>, rb_tree_tag, tree_order_statistics_node_update> mx;
tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> mi;
vector<pair<pii, int>> v;

signed main()
{
    fast;
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].F.F >> v[i].F.S;
        v[i].S = i;
    }
    sort(v.begin(), v.end(), [](pair<pii, int> p1, pair<pii, int> p2)
         { return pii{p1.F.F, -p1.F.S} < pii{p2.F.F, -p2.F.S}; });
    for (auto p : v)
    {
        sub[p.S] = mx.order_of_key({p.F.S - 1, n + 1});
        mx.insert({p.F.S, p.S});
    }
    reverse(v.begin(), v.end());
    for (auto p : v)
    {
        sup[p.S] = mi.order_of_key({p.F.S + 1, -1});
        mi.insert({p.F.S, p.S});
    }
    for (int i = 0; i < n; i++)
        cout << sup[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; i++)
        cout << sub[i] << " \n"[i == n - 1];
}
