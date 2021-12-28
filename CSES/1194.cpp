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

int n, m;
char mp[1005][1005];
int mdis[1005][1005], pdis[1005][1005];
pii pre[1005][1005];
queue<pii> qm, q;

signed main()
{
    //fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mdis[i][j] = pdis[i][j] = 10000000;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'M')
            {
                qm.push({i, j});
                mdis[i][j] = 0;
            }
            else if (mp[i][j] == 'A')
            {
                q.push({i, j});
                pdis[i][j] = 0;
            }
        }
    for (int i = 1; i <= n; i++)
        mp[i][0] = mp[i][m + 1] = '#';
    for (int j = 1; j <= m; j++)
        mp[0][j] = mp[n + 1][j] = '#';

    while (!qm.empty())
    {
        auto [x, y] = qm.front();
        qm.pop();
        if (mp[x + 1][y] != '#' && mdis[x + 1][y] > mdis[x][y] + 1)
        {
            mdis[x + 1][y] = mdis[x][y] + 1;
            qm.push({x + 1, y});
        }
        if (mp[x][y + 1] != '#' && mdis[x][y + 1] > mdis[x][y] + 1)
        {
            mdis[x][y + 1] = mdis[x][y] + 1;
            qm.push({x, y + 1});
        }
        if (mp[x - 1][y] != '#' && mdis[x - 1][y] > mdis[x][y] + 1)
        {
            mdis[x - 1][y] = mdis[x][y] + 1;
            qm.push({x - 1, y});
        }
        if (mp[x][y - 1] != '#' && mdis[x][y - 1] > mdis[x][y] + 1)
        {
            mdis[x][y - 1] = mdis[x][y] + 1;
            qm.push({x, y - 1});
        }
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (mp[x + 1][y] != '#' && pdis[x + 1][y] > pdis[x][y] + 1 && pdis[x][y] + 1 < mdis[x + 1][y])
        {
            pdis[x + 1][y] = pdis[x][y] + 1;
            pre[x + 1][y] = {x, y};
            q.push({x + 1, y});
        }
        if (mp[x][y + 1] != '#' && pdis[x][y + 1] > pdis[x][y] + 1 && pdis[x][y] + 1 < mdis[x][y + 1])
        {
            pdis[x][y + 1] = pdis[x][y] + 1;
            pre[x][y + 1] = {x, y};
            q.push({x, y + 1});
        }
        if (mp[x - 1][y] != '#' && pdis[x - 1][y] > pdis[x][y] + 1 && pdis[x][y] + 1 < mdis[x - 1][y])
        {
            pdis[x - 1][y] = pdis[x][y] + 1;
            pre[x - 1][y] = {x, y};
            q.push({x - 1, y});
        }
        if (mp[x][y - 1] != '#' && pdis[x][y - 1] > pdis[x][y] + 1 && pdis[x][y] + 1 < mdis[x][y - 1])
        {
            pdis[x][y - 1] = pdis[x][y] + 1;
            pre[x][y - 1] = {x, y};
            q.push({x, y - 1});
        }
    }
    int x, y, found = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pdis[i][1] <= m * n)
            x = i, y = 1, found = 1;
        if (pdis[i][m] <= m * n)
            x = i, y = m, found = 1;
    }
    for (int j = 1; j <= m; j++)
    {
        if (pdis[1][j] <= m * n)
            x = 1, y = j, found = 1;
        if (pdis[n][j] <= m * n)
            x = n, y = j, found = 1;
    }

    if (found)
    {
        cout << "YES\n";
        vector<pii> v;
        do
        {
            v.emplace_back(pii{x, y});
            pii nxt = pre[x][y];
            x = nxt.F, y = nxt.S;
        } while (pii{x, y} != pii{0, 0});
        cout << v.size() - 1 << '\n';

        for (int i = v.size() - 1; i >= 1; i--)
            if (v[i].F > v[i - 1].F)
                cout << 'U';
            else if (v[i].F < v[i - 1].F)
                cout << 'D';
            else if (v[i].S > v[i - 1].S)
                cout << 'L';
            else if (v[i].S < v[i - 1].S)
                cout << 'R';
    }
    else
        cout << "NO";
}
