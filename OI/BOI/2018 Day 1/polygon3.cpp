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
            tree_matching(i);

    for (int i = 1; i <= N; i++)
        if (!used[i])
            ans++;
    cout << ans << '\n';
}