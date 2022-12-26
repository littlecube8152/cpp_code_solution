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

int T, N, L[105], R[105];
char ans[105];
vector<int> in[105];
string s = "ACDEHIJKMORST";

void solve()
{
    mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
    cin >> N;
    for (int i = 1; i <= N; i++)
        in[i].clear();
    for (int i = 1; i <= N; i++)
    {
        cin >> L[i];
        in[L[i]].emplace_back(i);
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> R[i];
        in[R[i]].emplace_back(i);
    }
    int tries = 2000;
    vector<int> order;
    for (int i = 1; i <= N; i++)
        order.emplace_back(i);
    while (tries--)
    {
        bool valid = 1;
        for (int i = 1; i <= N; i++)
            ans[i] = 0;
        shuffle(order.begin(), order.end(), rd);
        for (int i : order)
        {
            vector<char> v, ch;
            for (int j : in[i])
                if (ans[j])
                    v.emplace_back(ans[j]);
            if (ans[L[i]])
                v.emplace_back(ans[L[i]]);
            v.emplace_back(ans[L[i]]);
            sort(v.begin(), v.end());
            v.resize(unique(v.begin(), v.end()) - v.begin());
            if (v.size() == 13)
            {
                valid = 1;
                goto sad;
            }
            for (char c : s)
            {
                bool can = 1;
                for (char d : v)
                    if (c == d)
                        can = 0;
                if (can)
                    ch.emplace_back(c);
            }
            ans[i] = ch[rd() % ch.size()];
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j : in[i])
                if (ans[i] == ans[j] || ans[i] == ans[L[i]] || ans[j] == ans[L[i]] || ans[i] == ans[R[i]] || ans[j] == ans[R[i]])
                {
                    valid = 0;
                    goto sad;
                }
        }
    sad:
        if (valid)
        {
            for (int i = 1; i <= N; i++)
                cout << ans[i];
            cout << '\n';
            return;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

signed main()
{
    fast;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}