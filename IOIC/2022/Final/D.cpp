#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
#define ll long long
//#define int long long

int dis[100005] = {}, vis[100005];

ll solve(int k, int m)
{
    for (int i = 0; i < k; i++)
        dis[i] = 46, vis[i] = 0;
    dis[1] = 1;
    deque<int> dq;
    dq.emplace_back(1);
    while (!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();
        if (vis[u])
            continue;
        vis[u] = 1;
        if (dis[(u + 1) % k] > dis[u] + 1)
        {
            dis[(u + 1) % k] = dis[u] + 1;
            dq.emplace_back((u + 1) % k);
        }
        if (dis[(u * 10) % k] > dis[u])
        {
            dis[(u * 10) % k] = dis[u];
            dq.emplace_front((u * 10) % k);
        }
    }
    //for (int i = 0; i < k; i++)
    //cout << dis[i] << " \n"[i == k - 1];
    return dis[m];
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int k, m;
        cin >> k >> m;
        cout << solve(k, m) << '\n';
    }
}