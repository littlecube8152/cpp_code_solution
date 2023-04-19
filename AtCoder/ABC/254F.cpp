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

int N, Q, A[200005], B[200005], tA[21][200005], tB[21][200005];

signed main()
{
    fast;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        tA[0][i] = abs(A[i] - A[i - 1]);
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> B[i];
        tB[0][i] = abs(B[i] - B[i - 1]);
    }
    for (int t = 1; t <= 20; t++)
        for (int i = 1; i <= N; i++)
            tA[t][i] = __gcd(tA[t - 1][i], tA[t - 1][min(i + (1 << (t - 1)), N)]);
    for (int t = 1; t <= 20; t++)
        for (int i = 1; i <= N; i++)
            tB[t][i] = __gcd(tB[t - 1][i], tB[t - 1][min(i + (1 << (t - 1)), N)]);
    for (int i = 1; i <= Q; i++)
    {
        int h1, h2, w1, w2, gh = 0, gw = 0;
        cin >> h1 >> h2 >> w1 >> w2;
        if (h1 != h2)
        {
            int ph = __lg(h2 - h1);
            gh = __gcd(tA[ph][h1 + 1], tA[ph][h2 - (1 << ph) + 1]);
        }
        if (w1 != w2)
        {
            int pw = __lg(w2 - w1);
            gw = __gcd(tB[pw][w1 + 1], tB[pw][w2 - (1 << pw) + 1]);
        }
        cout << __gcd(A[h1] + B[w1], __gcd(gh, gw)) << '\n';
    }
}
