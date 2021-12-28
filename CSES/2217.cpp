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
//using namespace __gnu_pbds;

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

ll n, q, pos[200005];
vector<pii> v = {{0, 2000005}};

int cal(int L, int R)
{
    ll last = v[L].S, ans = 0;
    for (int i = L + 1; i <= R; i++)
        if (v[i].S < last)
            ans++, last = v[i].S;
        else
            last = v[i].S;
    return ans;
}

signed main()
{
    fast;
    cin >> n >> q;
    v.resize(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].F;
        pos[i] = v[i].F;
        v[i].S = i;
    }
    v[n + 1] = {n + 1, 2000006};
    sort(v.begin(), v.end());
    int ans = cal(0, n);
    for (int i = 1; i <= q; i++)
    {
        int a, b, va, vb, old;
        cin >> a >> b;
        
        va = pos[a], vb = pos[b];
        if (va > vb)
            swap(a, b), swap(va, vb);
        old = (abs(va - vb) <= 1 ? cal(va - 1, vb + 1) : cal(va - 1, va + 1) + cal(vb - 1, vb + 1));
        swap(v[va].S, v[vb].S);
        swap(pos[a], pos[b]);
        ans += (abs(va - vb) <= 1 ? cal(va - 1, vb + 1) : cal(va - 1, va + 1) + cal(vb - 1, vb + 1)) - old;
        cout << ans << '\n';
    }
}
