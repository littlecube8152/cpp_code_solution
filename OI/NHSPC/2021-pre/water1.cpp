#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, Q, water[100005], pre[100005];
vector<int> E[100005];

void dfs(int k)
{
    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            water[k] += water[i];
            water[i] = 0;
            dfs(i);
            pre[i] = 0;
        }
    
}

signed main()
{
    cin >> N;
    for (int i = 1; i <= N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= N; i++)
        cin >> water[i];
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int v;
        cin >> v;
        cout << water[v] << " \n"[i == Q];
        water[v] = 0;
        dfs(v);
    }
}