/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int T, N, E, ans, deg[500005];
vector<int> edge[500005];
vector<int> degv[500005];

signed main()
{
    fast;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &N, &E);
        ans = 0;

        for (int i = 1; i <= E; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);

            edge[u].emplace_back(v);
            edge[v].emplace_back(u);
            deg[min(u, v)]++;
        }
        for (int i = 0; i < N; i++)
            ans = max(ans, deg[i]);
        cout << ans << " ";
        ans = 0;
        for (int i = 0; i < N; i++)
            deg[i] = 0;
        for (int i = 0; i < N; i++)
            for (int j : edge[i])
                deg[j]++;
        for (int i = 0; i < N; i++)
            degv[deg[i]].push_back(i);
        for (int i = 0; i <= E; i++)
        {
            for (int j = 0; j < degv[i].size(); j++)
                if (deg[degv[i][j]] > 0)
                {
                    //cout << "[" << degv[i][j] << ", " << deg[degv[i][j]] << "] ";
                    ans = max(ans, deg[degv[i][j]]);
                    while (!edge[degv[i][j]].empty())
                    {
                        int k = edge[degv[i][j]].back();
                        edge[degv[i][j]].pop_back();
                        if (deg[k] > 0)
                        {
                            deg[k]--;
                            if (deg[k] >= i)
                                degv[deg[k]].emplace_back(k);
                        }
                    }
                    deg[degv[i][j]] = 0;
                }
            degv[i].clear();
            degv[i].shrink_to_fit();
        }
        cout << ans << '\n';
        for (int i = 0; i < N; i++)
        {
            edge[i].clear();
            edge[i].shrink_to_fit();
        }
    }
}
