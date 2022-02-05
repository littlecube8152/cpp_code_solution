//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int pre[300005], n, m, k, x, y, w, child[300005];
bool inset[300005], vis[300005];
long long dis[300005];
set<pll> st;
vector<pll> e[300005];
map<pair<int, int>, int> edge;
set<pair<int, int>> result;
void dfs(int n)
{
    int res = 0;
    for (auto i : e[n])
        if (pre[i.first] == n)
        {
            dfs(i.first);
            res += child[i.first];
            result.insert(make_pair(child[i.first], edge[make_pair(n, i.first)]));
            edge.erase(make_pair(n, i.first));
            edge.erase(make_pair(i.first, n));
        }
    child[n] = res + 1;
}

signed main()
{
    fast;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> w;
        edge[{x, y}] = i;
        edge[{y, x}] = i;
        e[x].emplace_back(make_pair(y, w));
        e[y].emplace_back(make_pair(x, w));
    }
    for (int i = 2; i <= n; i++)
        dis[i] = 400000000000000;

    dis[1] = 0;
    st.insert(make_pair(0, 1));
    inset[1] = 1;


    while (!st.empty())
    {
        
        auto top = *st.begin();
        dis[top.second] = top.first;
        st.erase(st.begin());
        
        for (auto i : e[top.second])
            if (!vis[i.first])
            {
                if (dis[top.second] + i.second < dis[i.first])
                {
                    if (inset[i.first])
                        st.erase(make_pair(dis[i.first], i.first));

                    dis[i.first] = dis[top.second] + i.second;
                    st.insert(make_pair(dis[i.first], i.first));

                    pre[i.first] = top.second;
                    inset[i.first] = 1;
                }
            }

        inset[top.second] = 0;
        vis[top.second] = 1;
    }

    dfs(1);

    for (auto i : edge)
        result.insert(make_pair(0, i.second));
    while (result.size() > k)
        result.erase(result.begin());

    cout << k << '\n';
    set<int> edgeres;
    for (auto i : result)
        edgeres.insert(i.second);
    for (auto i : edgeres)
        cout << i << " ";
}