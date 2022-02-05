/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
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
//using namespace __gnu_pbds;

#define LOCAL

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

int n, m, ans;
bool vis[1005][1005];
char mp[1005][1005];
pii pre[1005][1005], st, en;

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'A')
                st = {i, j};
            else if (mp[i][j] == 'B')
            {
                mp[i][j] = '.';
                en = {i, j};
            }
        }
    queue<pii> q;
    pre[st.F][st.S] = {-1, -1};
    q.push(st);
    while (!q.empty())
    {
        pii p = q.front();
        int x = p.F, y = p.S;
        if (mp[x + 1][y] == '.' && pre[x + 1][y] == pii{0, 0})
        {
            pre[x + 1][y] = q.front();
            q.push({x + 1, y});
        }
        if (mp[x - 1][y] == '.' && pre[x - 1][y] == pii{0, 0})
        {
            pre[x - 1][y] = q.front();
            q.push({x - 1, y});
        }
        if (mp[x][y + 1] == '.' && pre[x][y + 1] == pii{0, 0})
        {
            pre[x][y + 1] = q.front();
            q.push({x, y + 1});
        }
        if (mp[x][y - 1] == '.' && pre[x][y - 1] == pii{0, 0})
        {
            pre[x][y - 1] = q.front();
            q.push({x, y - 1});
        }
        q.pop();
    }
    if (pre[en.F][en.S] == pii{0, 0})
        cout << "NO";
    else
    {
        vector<pii> v;
        cout << "YES\n";
        do
        {
            v.emplace_back(en);
            en = pre[en.F][en.S];
        } while (en != pii{-1, -1});
        cout << v.size() - 1 << '\n';
        for (int i = v.size() - 1; i >= 1; i--)
            if (v[i].F > v[i - 1].F)
                cout << "U";
            else if (v[i].F < v[i - 1].F)
                cout << "D";
            else if (v[i].S > v[i - 1].S)
                cout << "L";
            else if (v[i].S < v[i - 1].S)
                cout << "R";
    }
}
