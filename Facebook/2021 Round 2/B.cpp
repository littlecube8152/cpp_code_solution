/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
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

#define LOCAL

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int T, N, pre[800005], ans, f[800005], Size[800005], satisfy[800005];
map<int, int> dp[800005], original;
vector<int> edge[800005];

void dfs(int k)
{
    if(k % 10000 == 0)
    cout << k << '\n';
    int mxchild = 0;
    Size[k] = 1;
    for (int p : edge[k])
        if (p != pre[k])
        {
            pre[p] = k;
            dfs(p);
            Size[k] += Size[p];
            if (Size[p] > Size[mxchild])
                mxchild = p;
        }
    if (mxchild != 0)
        dp[k].swap(dp[mxchild]);
    dp[k][f[k]]++;
    if (dp[k][f[k]] == original[f[k]])
        dp[k].erase(f[k]);

    for (int p : edge[k])
        if (p != pre[k] && p != mxchild)
            for (auto pi : dp[p])
                if (pi.S != 0)
                {
                    dp[k][pi.F] += pi.S;
                    if (dp[k][pi.F] == original[pi.F])
                        dp[k].erase(pi.F);
                }
    if(k != 1 && dp[k].empty())
        ans++;
}

signed main()
{
    ifstream cin("chainblock_input.txt");
    ofstream cout("chainblock_output.txt");
    fast;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N;
        original.clear();
        ans = 0;
        for (int i = 1; i <= N; i++)
        {
            edge[i].clear();
            dp[i].clear();
            pre[i] = 0;
            Size[i] = 0;
        }
        for (int i = 1; i < N; i++)
        {
            int u, v;
            cin >> u >> v;
            edge[u].emplace_back(v);
            edge[v].emplace_back(u);
        }
        for (int i = 1; i <= N; i++)
        {
            cin >> f[i];
            original[f[i]]++;
        }
        dfs(1);
        cout << "Case #" << t << ": " << ans << '\n';
    }
}
