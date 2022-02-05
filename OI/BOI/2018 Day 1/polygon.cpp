#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, idx, pre[100005], vis[100005], visr[100005], deg[100005], ans;
bool used[100005];
map<string, int> mp;
vector<int> E[100005], rE[100005], newE[100005];
vector<pii> oE;
void dfs(int k, int r)
{
    for (int i : E[k])
        if (!vis[i] || (visr[i] == r && vis[i] == 1))
        {
            vis[i]++;
            visr[i] = r;
            dfs(i, r);
        }
}

void tree_matching(int k)
{
    for (int i : rE[k])
        if (vis[i] != 2)
            tree_matching(i);
    for (int i : rE[k])
        if (vis[i] != 2 && !used[i])
        {
            used[k] = used[i] = 1;
            ans++;
            break;
        }
}

void tree_matching2(int k)
{
    vis[k] = 3;
    for (int i : newE[k])
        if (vis[i] != 3 && !used[i])
            tree_matching2(i);
    for (int i : newE[k])
        if (!used[i])
        {
            used[k] = used[i] = 1;
            ans++;
            break;
        }
    vis[k] = 0;
}

#define debug(arr)               \
    for (int i = 1; i <= N; i++) \
        cout << arr[i] << " \n"[i == N];

signed main()
{
    cin >> N;
    if (N % 2 == 1)
    {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 1; i <= N; i++)
    {
        string s, t;
        cin >> s >> t;
        if (mp[s] == 0)
            mp[s] = ++idx;
        if (mp[t] == 0)
            mp[t] = ++idx;
        oE.emplace_back(make_pair(mp[s], mp[t]));
    }
    //for (auto p : mp)
    //    cout << p.F << " " << p.S << '\n';

    sort(oE.begin(), oE.end(), [](pii p1, pii p2)
         { return pii{min(p1.F, p1.S), max(p1.F, p1.S)} < pii{min(p2.F, p2.S), max(p2.F, p2.S)}; });
    for (int i = 1; i < N; i++)
        if (oE[i].F == oE[i - 1].S && oE[i].S == oE[i - 1].F)
            used[oE[i].F] = used[oE[i].S] = 1;

    //cout << "pair ";
    //debug(used);

    for (pii p : oE)
        if (!used[p.F])
        {
            int u = p.F, v = (used[p.S] ? p.F : p.S);
            E[u].emplace_back(v);
            rE[v].emplace_back(u);
        }
    mp.clear();
    for (int i = 1; i <= N; i++)
        if (!vis[i])
        {
            vis[i] = 1;
            visr[i] = i;
            dfs(i, i);
        }

    //cout << "vis ";
    //debug(vis);

    for (int i = 1; i <= N; i++)
        if (vis[i] == 2)
        {
            tree_matching(i);
            //cout << "firstTree ";
            //debug(used);
        }

    for (int i = 1; i <= N; i++)
        if (!used[i])
            for (int j : E[i])
                if (!used[j])
                    newE[i].emplace_back(j);
    for (int i = 1; i <= N; i++)
        if (!used[i])
            tree_matching2(i);

    //cout << "secondChain ";
    //debug(used);

    for (int i = 1; i <= N; i++)
        if (!used[i])
            ans++;
    cout << ans << '\n';
}