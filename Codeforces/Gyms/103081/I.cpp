#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, dis[100005], vis[100005];
vector<int> E[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for(int i = 1; i <= N; i++)
        dis[i] = 1e9;
    dis[1] = 0;
    vis[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : E[u])
            if(!vis[v])
            {
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
    }
    int mx = 0;
    for(int i = 1; i <= N; i++)
        mx = max(mx, dis[i]);
    if(mx >= 1e9)
        cout << -1 << '\n';
    else
    {
        if(mx == 1)
            cout << 1 << '\n';
        else 
            cout << __lg(mx - 1) + 2 << '\n';
    }
}
