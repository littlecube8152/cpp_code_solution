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
//#define int long long
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
using namespace __gnu_pbds;
// 2
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

int N;
pii p[1005];
vector<int> v;

inline ll dis(pii p1, pii p2)
{
    return (p1.F - p2.F) * (p1.F - p2.F) + (p1.S - p2.S) * (p1.S - p2.S);
}

inline bool check(vector<int> &g1, vector<int> &g2)
{
    //cout << "checking set ";
    //for (int i : g1)
    //    cout << i << " ";
    //cout << '\n';
    gp_hash_table<long long, bool, custom_hash> mp;
    for (int i : g1)
        for (int j : g2)
            mp[dis(p[i], p[j])] = 1;
    for (int i = 0; i < g1.size(); i++)
        for (int j = 0; j < i; j++)
            if (mp[dis(p[g1[i]], p[g1[j]])])
                return 0;
    for (int i = 0; i < g2.size(); i++)
        for (int j = 0; j < i; j++)
            if (mp[dis(p[g2[i]], p[g2[j]])])
                return 0;
    return 1;
}
void solve()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> p[i].F >> p[i].S;
    vector<int> v1, v2;
    std::mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
    bool b = 0;
    vector<int> v(N);
    for (int i = 1; i <= N; i++)
        v[i - 1] = i;
    while (!b)
    {
        v1.clear();
        v2.clear();
        for (int i = 1; i <= N; i++)
            if (rd() % 10)
                v1.pb(i);
            else
                v2.pb(i);
        if (v1.size() == N || v1.size() == 0)
            continue;
        b = check(v1, v2);
    }
    cout << v1.size() << '\n';
    for (int i : v1)
        cout << i << " ";
}

signed main()
{
    fast;
    solve();
}