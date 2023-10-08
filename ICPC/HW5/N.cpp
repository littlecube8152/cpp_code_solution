#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

#define sumS 500005
#define sigma 26
#define base 'a'
struct AhoCorasick
{
    int ch[sumS][sigma] = {{}}, f[sumS] = {-1}, tag[sumS], mv[sumS][sigma], jump[sumS], cnt[sumS];
    int idx = 0;
    int insert(string &s)
    {
        int j = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (!ch[j][s[i] - base])
                ch[j][s[i] - base] = ++idx;
            j = ch[j][s[i] - base];
        }
        tag[j] = 1;
        return j;
    }
    int next(int u, int c)
    {
        return u < 0 ? 0 : mv[u][c];
    }
    void build()
    {
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v = 0; v < sigma; v++)
            {
                if (ch[u][v])
                {
                    f[ch[u][v]] = next(f[u], v);
                    q.push(ch[u][v]);
                }
                mv[u][v] = (ch[u][v] ? ch[u][v] : next(f[u], v));
            }
            if (u)
                jump[u] = (tag[f[u]] ? f[u] : jump[f[u]]);
        }
    }
} ac;

int n, q, ans[500005], vis[500005];
string s, t;
vector<pii> qu[500005];
vector<int> E[500005];

void change(int state, int val)
{
    do
    {
        ac.cnt[state] += val;
        state = ac.jump[state];
    } while (state);
}

void dfs(int u, int state)
{
    vis[u] = 1;
    state = ac.next(state, s[u] - base);
    change(state, 1);
    for (auto [p, i] : qu[u])
        ans[i] = ac.cnt[p];
    for (auto v : E[u])
        if (!vis[v])
            dfs(v, state);
    change(state, -1);
}

signed main()
{
    fast;
    cin >> n;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int u;
        cin >> u >> t;
        qu[u].emplace_back(pii(ac.insert(t), i));
    }
    ac.build();
    dfs(1, 0);
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}