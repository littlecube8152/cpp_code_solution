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

int solve()
{
    int Q, ans = 0;
    string s;
    cin >> s;
    vector<int> v[26];
    for (int i = 0; i < s.size(); i++)
        v[s[i] - 'a'].emplace_back(i + 1);
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int L, R;
        cin >> L >> R;
        if ((R - L) % 2 == 1)
            continue;
        int mid = (L + R) / 2;
        if (L == R)
        {
            ans++;
            continue;
        }
        int diff = 0;

        for (int j = 0; j < 26; j++)
            diff += abs((upper_bound(v[j].begin(), v[j].end(), mid) - lower_bound(v[j].begin(), v[j].end(), L)) -
                    (upper_bound(v[j].begin(), v[j].end(), R) - lower_bound(v[j].begin(), v[j].end(), mid + 1)));
        if (diff == 1)
        {
            ans++;
            continue;
        }
        diff = 0;

        for (int j = 0; j < 26; j++)
            diff += abs((upper_bound(v[j].begin(), v[j].end(), mid - 1) - lower_bound(v[j].begin(), v[j].end(), L)) -
                    (upper_bound(v[j].begin(), v[j].end(), R) - lower_bound(v[j].begin(), v[j].end(), mid)));
        if (diff == 1)
        {
            ans++;
            continue;
        }
    }
    return ans;
}

signed main()
{
    fast;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cerr << "Start Case " << t << "...\n";
        cout << "Case #" << t << ": ";
        cout << solve() << '\n';
        cerr << "End Case " << t << ".\n";
    }
}
