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

int n, k;
vector<int> v[200005];

signed main()
{
    fast;
    string s;
    cin >> s;
    vector<int> zero, one;
    for (auto c : s)
    {
        ++n;
        if (c == '0')
        {
            if (one.empty())
            {
                zero.emplace_back(++k);
                v[k].emplace_back(n);
            }
            else
            {
                int i = one.back();
                v[i].emplace_back(n);
                one.pop_back();
                zero.emplace_back(i);
            }
        }
        else
        {
            if (zero.empty())
            {
                cout << -1 << '\n';
                return 0;
            }
            else
            {
                int i = zero.back();
                v[i].emplace_back(n);
                zero.pop_back();
                one.emplace_back(i);
            }
        }
    }
    if (!one.empty())
        cout << -1 << '\n';
    else
    {
        cout << k << '\n';
        for (int i = 1; i <= k; i++)
        {
            cout << v[i].size();
            for (int j : v[i])
                cout << ' ' << j;
            cout << '\n';
        }
    }
}
