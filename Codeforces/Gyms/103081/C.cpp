#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll X, Y, N, vis[1005];
pdd p[1005];

int dfs(int u, double d)
{
    vis[u] = 1;
    int ans = 0;
    if(p[u].F - d <= 0 || p[u].S + d >= Y)
        ans |= 1;
    if(p[u].F + d >= X || p[u].S - d < 0)
        ans |= 2;
    for(int v = 1; v <= N; v++)
        if(!vis[v] && 4.0 * d * d >= (p[u].F - p[v].F) * (p[u].F - p[v].F) + (p[u].S - p[v].S) * (p[u].S - p[v].S))
            ans |= dfs(v, d);
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> X >> Y >> N;
    for (int i = 1; i <= N; i++)
        cin >> p[i].F >> p[i].S;
    double L = 0, R = 1e9;
    while (abs(R - L) > 1e-7)
    {
        double mid = (L + R) / 2;
        for (int i = 1; i <= N; i++)
            vis[i] = 0;
        bool valid = 1;
        for (int i = 1; i <= N; i++)
            if (!vis[i])
            {
                if (dfs(i, mid) == 3)
                    valid = 0;
            }
        if (valid)
            L = mid;
        else
            R = mid;
    }
    cout << fixed << setprecision(10) << L << '\n';
}
