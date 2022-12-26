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

int N, K, p[200005];
deque<int> ans1, ans2, ans3;

signed main()
{
    fast;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> p[i];
    for (int i = 1; i <= N; i++)
        ans3.emplace_back(p[i]);
    int front = 1e9, op = 0;
    for (int i = 1; i <= K + 1; i++)
        if (p[i] < front)
            front = p[i], op = i - 1;
    if (front < 1e9)
    {
        int cur = K - op;
        for (int i = op + 1; i <= N; i++)
        {
            while (!ans1.empty() && ans1.back() > p[i] && cur)
            {
                cur--;
                ans1.pop_back();
            }
            ans1.push_back(p[i]);
        }
        for (int i = 1; i <= cur; i++)
            ans1.pop_back();
    }

    front = 1e9, op = 0;
    for (int i = N; i >= N - K + 1; i--)
        if (p[i] < front)
            front = p[i], op = N - i + 1;
    if (front < 1e9)
    {
        int cur = K - op;
        int remain = op;
        for (int i = N - op + 1; i <= N; i++)
        {
            while (!ans2.empty() && ans2.back() > p[i])
            {
                ans2.pop_back();
                remain--;
            }
            ans2.push_back(p[i]);
        }
        for (int i = 1; i <= N - op; i++)
        {
            while (!ans2.empty() && ans2.back() > p[i] && (ans2.size() <= remain || cur))
            {
                if (ans2.size() <= remain)
                    remain--;
                else
                    cur--;
                ans2.pop_back();
            }
            ans2.push_back(p[i]);
        }
        for (int i = 1; i <= cur; i++)
            ans2.pop_back();
    }
    // for (int i : ans1)
    //     cout << i << ' ';
    // cout << '\n';
    // for (int i : ans2)
    //     cout << i << ' ';
    // cout << '\n';
    // for (int i : ans3)
    //     cout << i << ' ';
    // cout << '\n';
    if (ans1.empty())
        ans1 = deque<int>(N, 1e9);
    if (ans2.empty())
        ans2 = deque<int>(N, 1e9);
    ans1 = min({ans1, ans2, ans3});
    for (int i : ans1)
        cout << i << ' ';
}
