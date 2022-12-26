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

int N, P[400005], Q[400005], sol[400005];

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= 2 * N; i++)
        cin >> P[i];
    for (int i = 1; i <= 2 * N; i++)
        cin >> Q[i];
    for (int i = 1; i <= N; i++)
        if (P[2 * i - 1] > P[2 * i])
            sol[P[2 * i - 1]] = 1, sol[P[2 * i]] = -1;
    for (int i = 1; i <= N; i++)
        if (Q[2 * i - 1] < Q[2 * i])
            sol[Q[2 * i - 1]] = 1, sol[Q[2 * i]] = -1;

    bool valid = 1;
    vector<int> L, R;
    N *= 2;
    for (int i = N; i >= 1; i--)
        if (sol[i] == 1)
            L.emplace_back(i);
        else if (sol[i] == -1)
            R.emplace_back(i);
        else
        {
            cout << -1 << '\n';
            return 0;
        }
    if (L.size() != R.size())
    {
        cout << -1 << '\n';
        return 0;
    }
    int acc = 0;
    for (int i = 1; i <= N; i++)
    {
        int cur;
        if (acc && (L.empty() || R.back() < L.back()))
        {
            acc--;
            cur = R.back();
            R.pop_back();
        }
        else
        {
            acc++;
            cur = L.back();
            L.pop_back();
        }
        if (cur != P[i])
            valid = 0;
    }

    for (int i = 1; i <= N; i++)
        if (sol[i] == 1)
            L.emplace_back(i);
        else if (sol[i] == -1)
            R.emplace_back(i);
    acc = 0;
    for (int i = 1; i <= N; i++)
    {
        int cur;
        if (acc && (L.empty() || R.back() > L.back()))
        {
            acc--;
            cur = R.back();
            R.pop_back();
        }
        else
        {
            acc++;
            cur = L.back();
            L.pop_back();
        }
        if (cur != Q[i])
            valid = 0;
    }
    if (valid)
    {
        for (int i = 1; i <= N; i++)
            cout << (sol[i] == 1 ? '(' : ')');
        cout << '\n';
        return 0;
    }
    cout << -1 << '\n';
}
