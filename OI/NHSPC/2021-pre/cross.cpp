#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, m;
vector<vector<ll>> mp, u, d, l, r;
ll ans;

void init(vector<vector<ll>> &v)
{
    v.resize(n);
    for (auto &u : v)
        u.resize(m);
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    init(mp), init(u), init(d), init(l), init(r);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];
    for (int i = 0; i < n; i++)
    {
        vector<pii> v;
        for (int j = 0; j < m; j++)
        {
            while (!v.empty() && mp[i][j] > v.back().F)
            {
                r[i][v.back().S] = j - v.back().S - 1;
                v.pop_back();
            }
            v.emplace_back(pii{mp[i][j], j});
        }
        for (pii p : v)
            r[i][p.S] = m - p.S - 1;
    }
    for (int i = 0; i < n; i++)
    {
        vector<pii> v;
        for (int j = m - 1; j >= 0; j--)
        {
            while (!v.empty() && mp[i][j] > v.back().F)
            {
                l[i][v.back().S] = v.back().S - j - 1;
                v.pop_back();
            }
            v.emplace_back(pii{mp[i][j], j});
        }
        for (pii p : v)
            l[i][p.S] = p.S;
    }
    for (int j = 0; j < m; j++)
    {
        vector<pii> v;
        for (int i = 0; i < n; i++)
        {
            while (!v.empty() && mp[i][j] > v.back().F)
            {
                d[v.back().S][j] = i - v.back().S - 1;
                v.pop_back();
            }
            v.emplace_back(pii{mp[i][j], i});
        }
        for (pii p : v)
            d[p.S][j] = n - p.S - 1;
    }
    for (int j = 0; j < m; j++)
    {
        vector<pii> v;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!v.empty() && mp[i][j] > v.back().F)
            {
                u[v.back().S][j] = v.back().S - i - 1;
                v.pop_back();
            }
            v.emplace_back(pii{mp[i][j], i});
        }
        for (pii p : v)
            u[p.S][j] = p.S;
    }
    /*
    cout << "L\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << l[i][j] << " \n"[j == m - 1];
    cout << "R\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << r[i][j] << " \n"[j == m - 1];
    cout << "U\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << u[i][j] << " \n"[j == m - 1];
    cout << "D\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << d[i][j] << " \n"[j == m - 1];
    */
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = (ans + min(l[i][j], r[i][j]) * (d[i][j] + d[i][j] - min(u[i][j], d[i][j]) + 1) * min(u[i][j], d[i][j]) / 2) % 1000000007;
    cout << ans << '\n';
}