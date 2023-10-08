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

bool solve()
{
    int N, K;
    cin >> N >> K;
    vector<int> s(N), ss(2 * N), t(N + 1, 0);
    for (int i = 0; i < N; i++)
        cin >> s[i];
    for (int i = 1; i <= N; i++)
        cin >> t[i];
    for (int i = 0; i < N; i++)
        ss[i] = ss[i + N] = s[i];

    if (K == 0)
    {
        bool valid = 1;
        for (int i = 1; i <= N; i++)
            if (s[i - 1] != t[i])
                valid = 0;
        return valid;
    }

    if(N == 2)
    {
        if (K % 2 == 1)
            return s[0] == t[2] && s[1] == t[1];
        else
            return s[0] == t[1] && s[1] == t[2];
    }

    vector<int> match;
    vector<int> f(t.size(), 0);
    f[0] = -1;
    for (int i = 1, j = -1; i < t.size(); i++)
    {
        while (j >= 0)
            if (t[j + 1] == t[i])
                break;
            else
                j = f[j];
        f[i] = ++j;
    }

    for (int i = 0, j = 0; i < ss.size(); i++)
    {
        while (j >= 0)
            if (t[j + 1] == ss[i])
                break;
            else
                j = f[j];
        if (++j + 1 == t.size())
        {
            match.emplace_back(i);
            j = f[j];
        }
    }
    for (int id : match)
    {
        if (id && K >= 2)
            return 1;
        if (id % N != N - 1)
            return 1;
    }
    return 0;
}

signed main()
{
    fast;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
        cout << "Case #" << t << ": " << (solve() ? "YES\n" : "NO\n");
}
