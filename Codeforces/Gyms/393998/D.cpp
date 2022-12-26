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

int n, r, sat[1005][2], idx;
string s;
vector<int> v;

void reject(int i, bool rec)
{
    cin >> s;
    char c1 = s[i - 1], c2 = s[i % n];
    c1 = (c1 == 'A' ? 'B' : 'A');
    c2 = (c2 == 'A' ? 'B' : 'A');
    cout << i << ' ' << c1 << ' ' << i % n + 1 << ' ' << c2 << endl;
    if (rec)
    {
        sat[i][c1 == 'A'] = ++idx;
        sat[i % n + 1][c2 == 'A'] = -idx;
    }
    cin >> r;
    if (r == 0)
        assert(0); 
}

int dec(int k)
{
    return (k - 1 == 0 ? k - 1 + n : k - 1);
}

int inc(int k) //
{
    return k % n + 1;
}

signed main()
{
    fast;
    cin >> n;
    vector<int> v;
    int cur = 1;
    for (int i = 1; i < n; i++)
    {
        reject(cur, 1);

        cur = 0;
        for (int j = 1; j <= n; j++)
            if (((sat[j][0] != 0) ^ (sat[j][1] != 0)) && !((s[j - 1] == 'A') ^ (sat[j][0] == 1)))
            {
                cur = j;
                if(sat[j][0] + sat[j][1] > 0)
                    cur = dec(j);
            }
        assert(cur != 0);
    }
    for (int i = 1; i < n; i++)
    {
        int cur = 0, id;
        // for (int j = 1; j <= n; j++)
        //     cout << sat[j][0] << " \n"[j == n];
        // for (int j = 1; j <= n; j++)
        //     cout << sat[j][1] << " \n"[j == n];
        for (int j = 1; j <= n; j++)
            if (((sat[j][0] != 0) ^ (sat[j][1] != 0)) && !((s[j - 1] == 'A') ^ (sat[j][0] == 1)))
                cur = j, id = sat[j][0] + sat[j][1];
        assert(cur != 0);
        if (id < 0)
            reject(dec(cur), 0);
        else
            reject(cur, 0);
        for (int j = 1; j <= n; j++)
        {
            if (abs(sat[j][0]) == abs(id))
                sat[j][0] = 0; //
            if (abs(sat[j][1]) == abs(id))
                sat[j][1] = 0;
        }
        
    }
    reject(1, 0);
    cin >> s;
    cout << "OK\n";
}
