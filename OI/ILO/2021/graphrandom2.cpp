#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

signed main()
{
    int n, m, ans = 0;
    vector<pii> best;
    cin >> n;
    vector<pii> v;
    m = n * (n - 1) / 2;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            v.emplace_back(make_pair(i, j));

    for (ll mask = 0; mask < 40000; mask++)
    {
        mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
        shuffle(v.begin(), v.end(), rd);
        int deg[105] = {}, adj[105][105] = {{}}, validcnt, valid[105][105] = {{}};
        for (int i = 0; i < m; i++)
        {
            deg[v[i].F]++, deg[v[i].S]++;
            adj[v[i].F][v[i].S]++;
            adj[v[i].S][v[i].F]++;
            for (int j = 1; j <= n; j++)
                if (adj[v[i].F][j] > 0 && __gcd(deg[v[i].F], deg[j]) != 1)
                {
                    if (valid[v[i].F][j])
                        validcnt--;
                    valid[v[i].F][j] = valid[j][v[i].F] = false;
                }
                else if (adj[v[i].F][j] > 0)
                {
                    if (!valid[v[i].F][j])
                        validcnt++;
                    valid[v[i].F][j] = valid[j][v[i].F] = true;
                }
            for (int j = 1; j <= n; j++)
                if (adj[v[i].S][j] > 0 && __gcd(deg[v[i].S], deg[j]) != 1)
                {
                    if (valid[v[i].S][j])
                        validcnt--;
                    valid[v[i].S][j] = valid[j][v[i].S] = false;
                }
                else if (adj[v[i].S][j] > 0)
                {
                    if (!valid[v[i].S][j])
                        validcnt++;
                    valid[v[i].S][j] = valid[j][v[i].S] = true;
                }
            if (validcnt == i + 1 && i > ans)
            {
                ans = i + 1;
                best = v;
            }
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < ans; i++)
        cout << "{" << best[i].F << ", " << best[i].S << "},\n";
}