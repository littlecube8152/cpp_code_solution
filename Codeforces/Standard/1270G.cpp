#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int T, N, a[1000006], vis[1000006];

void dfs(int u)
{
    vis[u]++;
    if(vis[a[u]] < 2)
        dfs(a[u]);
}

signed main()
{
    fast;
    cin >> T;
    while(T--)
    {
        cin >> N;
        fill(vis + 1, vis + 1 + N, 0);
        for (int i = 1; i <= N; i++)
        {
            int b;
            cin >> b;
            a[i] = -b + i;
        }
        dfs(1);
        vector<int> sol;
        for (int i = 1; i <= N; i++)
            if(vis[i] == 2)
                sol.emplace_back(i);
        cout << sol.size() << '\n';
        for (int i = 0; i < sol.size(); i++)
            cout << sol[i] << " \n"[i + 1 == sol.size()];
    }
}