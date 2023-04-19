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

int n, r;
string s;
vector<int> v;

int reject(int i)
{
    cin >> s;
    char c1 = s[i - 1], c2 = s[i % n];
    c1 = (c1 == 'A' ? 'B' : 'A');
    c2 = (c2 == 'A' ? 'B' : 'A');
    cout << i << ' ' << c1 << ' ' << i % n + 1 << ' ' << c2 << endl;
    cin >> r;
    if (r == 0)
        assert(0);
    if (s[i - 1] == c1)
        return -1;
    return 1;
}

signed main()
{
    fast;
    cin >> n;
    int l = 1, r = 2, cur = 1;
    for (int i = 1; i <= n; i++)
    {
        if (reject(cur) == -1)
        {
            l--;
            if (!l)
                l += n;
            cur = l;
        }
        else
        {
            cur = r;
            r = r % n + 1;
        }
    }
    
    for (int i = 1; i < n; i++)
        reject(i);
    cin >> s;
    cout << "OK\n";
}
