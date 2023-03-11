#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, k, pre[120005], vis[120005], match[120005], cnt, ans;
bitset<30000 * 20 * 2> b;
vector<pii> E[120005], T[120005];
pair<pii, int> nT;
vector<int> cV;
bool valid = 1;

void dfs(int u)
{
    cnt += (u <= 2 * n ? 1 : -1);
    cV.emplace_back(u);
    vis[u] = 1;
    for (auto [v, w] : E[u])
        if (!vis[v])
        {
            T[u].emplace_back(pii(v, w));
            pre[v] = u;
            dfs(v);
        }
        else if (v != pre[u])
            nT = make_pair(pii(u, v), w);
}

int matching(int u)
{
    int tot = 0;
    for (auto [v, w] : T[u])
    {
        tot += matching(v);
        if (!match[u] && !match[v])
            match[u] = match[v] = 1, tot += w;
    }
    return tot;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= 2 * n; i++)
    {
        int l, r, w;
        cin >> l >> r >> w;
        E[i].emplace_back(pii(2 * n + l, w));
        E[2 * n + l].emplace_back(pii(i, w));
        E[i].emplace_back(pii(3 * n + r, -w));
        E[3 * n + r].emplace_back(pii(i, -w));
    }
    b[20 * n + 1] = 1;
    for (int i = 1; i <= 2 * n; i++)
        if (!vis[i])
        {
            cV.clear();
            dfs(i);

            if (cnt != 0)
            {
                cout << "NO\n";
                cerr << "there is no perfect matching (vertex)\n";
                return 0;
            }
            vector<int> sol;
            bool mvalid = 1;
            int res = matching(i);
            for (auto j : cV)
            {
                mvalid &= match[j];
                match[j] = 0;
            }
            if (mvalid)
                sol.emplace_back(res);

            match[nT.F.F] = match[nT.F.S] = 1;
            mvalid = 1;
            res = nT.S + matching(i);
            for (auto j : cV)
                mvalid &= match[j];
            if (mvalid)
                sol.emplace_back(res);

            if (sol.size() == 0)
            {
                cout << "NO\n";
                cerr << "there is no perfect matching (dfs)\n";
                return 0;
            }

            ans += sol[0];
            if (sol.size() == 2)
            {
                int j = sol[1] - sol[0];
                if (j < 0)
                    b |= b >> (-j);
                else
                    b |= b << j;
            }
        }
    for (int i = 20 * n + 1 - k - ans; i <= 20 * n + 1 + k - ans; i++)
        if (b[i])
        {
            cout << "YES\n";
            return 0;
        }
    cout << "NO\n";
    cerr << "k is too small\n";
}