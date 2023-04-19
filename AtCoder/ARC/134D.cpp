/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
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
#define _INFINITY 9223372036854775807
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

ll N;
pii p[100005];

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> p[i].F;
    for (int i = 1; i <= N; i++)
        cin >> p[i].S;
    vector<int> F;
    vector<pii> S;

    auto push = [&](pii p)
    {
        F.push_back(p.F);
        if (!S.empty() && S.back().F == p.S)
            S.back().S++;
        else
            S.push_back(pii(p.S, 1));
    };

    for (int i = 1; i <= N; i++)
    {
        while (!F.empty() && (p[i].F < F.back()))
        {
            F.pop_back();
            if (--S.back().S == 0)
                S.pop_back();
        }
        if (F.empty() || p[i].F < S[0].F)
            push(p[i]);
        else if (S.size() >= 2 && p[i].F == S[0].F && S[0].F < S[1].F)
            push(p[i]);
    }
    if (F.size() >= 2)
        for (int i = 1; i <= N; i++)
        {
            if (vector<int>{p[i].F, p[i].S} < F)
            {
                F = vector<int>{p[i].F, p[i].S};
                S.clear();
            }
        }
    for (int i : F)
        cout << i << " ";
    for (auto [i, j] : S)
        for (int t = 1; t <= j; t++)
            cout << i << " ";
}
