/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

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

int n, m, k, x[100005];
string r[100005], w[100005];

string modify(string s, int mask)
{
    for (int i = 0; i < k; i++)
        if (mask >> i & 1)
            s[i] = '_';
    return s;
}

int h(string s)
{
    int res = 0;
    for (auto c : s)
        res = res * 27 + (c == '_' ? 26 : (int)(c - 'a'));
    return res;
}

set<string> st[27 * 27 * 27 * 27];
vector<string> mat[100005];
int remain[27 * 27 * 27 * 27], large[27 * 27 * 27 * 27];
int vis[100005];

signed main()
{
    fast;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i] >> x[i];
        for (int j = 0; j < k; j++)
            if (!(w[i][j] == r[x[i]][j] || r[x[i]][j] == '_'))
            {
                cout << "NO\n";
                return 0;
            }
        mat[x[i]].emplace_back(w[i]);
    }

    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (mat[i].size())
        {
            if (large[h(r[i])] != 0)
            {
                cout << "NO\n";
                return 0;
            }
            large[h(r[i])] = i;
            remain[h(r[i])] -= (int)mat[i].size();
        }
        for (auto s : mat[i])
            for (int mask = 0; mask < (1 << k); mask++)
                remain[h(modify(s, mask))]++;
    }
    for (int i = 1; i <= n; i++)
        if (mat[i].size() && remain[h(r[i])] == 0)
        {
            vis[i] = 1;
            q.push(i);
        }

    while (!q.empty())
    {
        auto i = q.front();
        q.pop();
        ans.emplace_back(i);
        for (auto s : mat[i])
            for (int mask = 0; mask < (1 << k); mask++)
            {
                int val = h(modify(s, mask));
                if (--remain[val] == 0 && large[val])
                {
                    vis[large[val]] = 1;
                    q.push(large[val]);
                }
            }
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            if(mat[i].size())
            {
                cout << "NO\n";
                return 0;
            }
            ans.emplace_back(i);
        }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
}
