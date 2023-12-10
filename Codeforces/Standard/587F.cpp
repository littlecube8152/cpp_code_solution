/* complexity: O(N^1.5) */

#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;

#define sumS 100005
#define sigma 26
#define base 'a'

struct AhoCorasick
{
    int ch[sumS][sigma] = {{}}, f[sumS] = {-1}, tag[sumS], mv[sumS][sigma], jump[sumS], cnt[sumS];
    int idx = 0, t = -1;
    pii o[sumS];
    vector<int> E[sumS], q;
    int insert(string &s, int t)
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
    void dfs(int u)
    {
        o[u].F = ++t;
        for (auto v : E[u])
            dfs(v);
        o[u].S = t;
    }
    void build()
    {
        int k = -1;
        q.emplace_back(0);
        while (++k < q.size())
        {
            int u = q[k];
            for (int v = 0; v < sigma; v++)
            {
                if (ch[u][v])
                {
                    f[ch[u][v]] = next(f[u], v);
                    q.emplace_back(ch[u][v]);
                }
                mv[u][v] = (ch[u][v] ? ch[u][v] : next(f[u], v));
            }
            if (u)
                jump[u] = (tag[f[u]] ? f[u] : jump[f[u]]);
        }
        reverse(q.begin(), q.end());
        for (int i = 1; i <= idx; i++)
            E[f[i]].emplace_back(i);
        dfs(0);
    }
    vector<int> small(string &s)
    {
        vector<int> st;
        for (int i = 0, j = 0; i < (int)s.size(); i++)
        {
            j = next(j, s[i] - base);
            st.emplace_back(j);
        }
        return st;
    }
    void large(string &s)
    {
        for (int i = 0; i <= idx; i++)
            cnt[i] = 0;
        for (int i = 0, j = 0; i < (int)s.size(); i++)
        {
            j = next(j, s[i] - base);
            cnt[j]++;
        }
        for (int i : q)
            if (f[i] > 0)
                cnt[f[i]] += cnt[i];
    }
} ac;

const int K = 400;
int n, q, id[100005];
ll a[100005], ans[100005], blk[1005];
string s[100005];
vector<pair<int, pii>> large[100005];
vector<pii> small[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        id[i] = ac.insert(s[i], i);
    }
    ac.build();

    for (int i = 1; i <= q; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        if (s[k].size() > K)
            large[k].emplace_back(i, pii(l, r));
        else
            small[l - 1].emplace_back(i, -k),
                small[r].emplace_back(i, k);
    }

    for (int i = 1; i <= n; i++)
        if (s[i].size() > K)
        {
            ac.large(s[i]);
            for (int j = 1; j <= n; j++)
                a[j] = a[j - 1] + ac.cnt[id[j]];

            for (auto [k, r] : large[i])
                ans[k] = a[r.S] - a[r.F - 1];
        }
    fill(a, a + ac.idx + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        auto [l, r] = ac.o[id[i]];
        if (r - l <= 2 * K)
            for (int j = l; j <= r; j++)
                a[j]++;
        else
        {
            int lB = (l - 1) / K + 1, rB = r / K - 1;
            for (int j = l; j < lB * K; j++)
                a[j]++;
            for (int j = lB; j <= rB; j++)
                blk[j]++;
            for (int j = (rB + 1) * K; j <= r; j++)
                a[j]++;
        }
        for (auto [p, k] : small[i])
        {
            int sgn = (k < 0 ? -1 : 1);
            k = abs(k);
            for (int j : ac.small(s[k]))
            {
                j = ac.o[j].F;
                ans[p] += sgn * (a[j] + blk[j / K]);
            }
        }
    }

    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}