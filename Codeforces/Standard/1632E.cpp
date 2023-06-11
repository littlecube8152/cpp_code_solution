/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
//using namespace __gnu_pbds;

int T, N, mxdis, dp[300005], pre[300005], dis[300005];
vector<int> E[300005];

void dfs(int k)
{
    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            dis[i] = dis[k] + 1;
            dfs(i);
        }
    mxdis = max(mxdis, dis[k]);
}

void dfs2(int k)
{
    for (int i : E[k])
        if (i != pre[k])
        {
            dfs2(i);
            dp[k] += dp[i];
        }
    if (dis[k] == mxdis)
        dp[k] = 1;
}

signed main()
{
    fast;
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 1; i < N; i++)
        {
            int u, v;
            cin >> u >> v;
            E[u].emplace_back(v);
            E[v].emplace_back(u);
        }
        dfs(1);
        dfs2(1);
        int deep = 1;
        for (int i = 2; i <= N; i++)
            if (dp[i] == dp[1] && dis[i] > dis[deep])
                deep = i;
        for (int i = 1; i <= N; i++)
        {
            int L = 0, R = dis[deep], ans = 1e6;
            while (L < R)
            {
                int mid = (L + R + 1) / 2;
                if ((mid + i) / 2 > min(mxdis, i + mxdis - mid))
                    R = mid - 1;
                else
                    L = mid;
            }
            for (int opt = max(0, L - 1); opt <= min(L + 1, dis[deep]); opt++)
                ans = min(ans, max((opt + i) / 2, min(mxdis, i + mxdis - opt)));
            cout << ans << " \n"[i == N];
        }
        for (int i = 1; i <= N; i++)
        {
            E[i].clear();
            dis[i] = pre[i] = dp[i] = 0;
        }
        mxdis = 0;
    }
}
/*
1
7  
1 2
2 3
3 4
4 5
5 6
5 7
*/