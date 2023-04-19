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

string solve(string s)
{
    string ans;
    for (int i = 1; i < s.length(); i++)
        if (s.length() % i == 0)
        {
            string res, fres;
            ll base = 1, L = 0, R = 1;
            for (int j = 1; j <= i; j++)
                base *= 10;
            L = (base / 10) - 1;
            R = base - 1;
            while (L < R)
            {
                ll mid = (L + R + 1) / 2, mid2 = mid;
                string l, f;
                for (int j = 1; j <= i; j++)
                {
                    l = char('0' + (mid2 % 10)) + l;
                    mid2 /= 10;
                }
                for (int j = 1; j <= s.length() / i; j++)
                    f = f + l;
                if (f <= s)
                    L = mid;
                else
                    R = mid - 1;
            }
            if (L >= base / 10)
            {
                for (int j = 1; j <= i; j++)
                {
                    res = char('0' + (L % 10)) + res;
                    L /= 10;
                }
                for (int j = 1; j <= s.length() / i; j++)
                    fres = fres + res;
                ans = max(ans, fres);
            }
        }
    while (!ans.empty() && ans.front() == '0')
        ans.erase(ans.begin());
    return ans;
}

signed main()
{
    fast;
    int T;
    cin >> T;
    while (T--)
    {
        string s, ans, ans2;
        cin >> s;
        ans = string(s.size() - 1, '9');
        ans2 = solve(s);
        cout << (ans.size() > ans2.size() ? ans : ans2) << '\n';
    }
}
