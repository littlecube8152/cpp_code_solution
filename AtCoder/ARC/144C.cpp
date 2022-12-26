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

ll ans[300005];

signed main()
{
    fast;
    int N, K;
    cin >> N >> K;
    if (K * 2 > N)
    {
        cout << -1;
        return 0;
    }
    else
    {
        vector<int> v;
        for (int i = 1; i <= N;)
        {
            int sz = (N - i + 1 < 4 * K ? N - i + 1 : 2 * K);

            if (sz >= 3 * K + 1)
            {
                int off = 4 * K - sz;
                for (int j = K; j < 2 * K; j++)
                    v.emplace_back(i + j);
                for (int j = 0; j < K - off; j++)
                    v.emplace_back(i + j);
                i += 2 * K - off;
                for (int j = K; j < 2 * K; j++)
                    v.emplace_back(i + j);
                for (int j = 0; j < K; j++)
                    v.emplace_back(j < off ? i + j - K : i + j);
                i += 2 * K;
                break;
            }
            for (int j = K; j < sz; j++)
                v.emplace_back(i + j);
            for (int j = 0; j < K; j++)
                v.emplace_back(i + j);
            i += sz;
        }
        for (int i = 1; i <= N; i++)
            cout << v[i - 1] << " \n"[i == N];
    }
}
