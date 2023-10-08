#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,popcnt,fma")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, m, d, r[5000], u[5000], ans = 5000 * 5000, p[5000][5000];
vector<int> x[5000], y[5000];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++)
    {
        int p, q;
        cin >> p >> q;
        x[0].emplace_back(p);
        x[0].emplace_back(p + d);
        y[0].emplace_back(q);
        y[0].emplace_back(q + d);
    }
    sort(x[0].begin(), x[0].end());
    sort(y[0].begin(), y[0].end());
    for (int i = 0; i < d; i++)
    {
        auto iter = lower_bound(x[0].begin(), x[0].end(), i + d);
        if (iter == x[0].begin())
            r[i] = i;
        else
            r[i] = max(i, *prev(iter));
    }
    for (int i = 0; i < d; i++)
    {
        auto iter = lower_bound(y[0].begin(), y[0].end(), i + d);
        if (iter == y[0].begin())
            u[i] = i;
        else
            u[i] = max(i, *prev(iter));
    }
    x[0].clear(), y[0].clear();
    for (int i = 1; i <= m; i++)
    {
        int r, s;
        cin >> r >> s;
        x[r].emplace_back(s);
        x[r].emplace_back(s + d);
    }
    for (int i = 0; i < d; i++)
    {
        vector<int> occ(d * 2);
        for (int j : x[i])
            occ[j]++;
        if (occ[0] == 0)
            occ[0] = -1;
        for (int j = 1; j < 2 * d; j++)
            if (occ[j])
                occ[j] = j;
            else
                occ[j] = occ[j - 1];
        for (int j = 0; j < d; j++)
            p[j][i] = (occ[j + d - 1] <= j ? -1 : occ[j + d - 1]);
    }
    for (int i = 0; i < d; i++)
    {
        deque<pii> mono;
        for (int j = 0; j < d; j++)
            if (p[i][j] >= 0)
            {
                while (!mono.empty() && mono.back().S <= p[i][j])
                    mono.pop_back();
                mono.emplace_back(pii(j, p[i][j]));
            }
        for (int j = 0; j < d; j++)
        {
            // cerr << i << ' ' << j << ':';
            for (auto [x, y] : mono)
                // cerr << "(" << x << ", " << y << ")";
                // cerr << '\n';
                if (!mono.empty() && mono.front().F == j)
                    mono.pop_front();
            if (mono.empty())
            {
                ans = min(ans, (u[i] - i + 1) * (r[j] - j + 1));
                // cerr << (u[i] - i + 1) * (r[j] - j + 1) << '\n';
            }
            else
            {
                ans = min(ans, (max(mono.front().S, u[i]) - i + 1) * (r[j] - j + 1));
                // cerr << (max(mono.front().S, u[i]) - i + 1) * (r[j] - j + 1) << ' ';
                for (int k = 0; k + 1 < mono.size(); k++)
                {
                    ans = min(ans, (max(mono[k + 1].S, u[i]) - i + 1) * (max(mono[k].F, r[j]) - j + 1));
                    // cerr << (max(mono[k + 1].S, u[i]) - i + 1) * (max(mono[k].F, r[j]) - j + 1) << ' ';
                }
                ans = min(ans, (u[i] - i + 1) * (max(mono.back().F, r[j]) - j + 1));
                // cerr << (u[i] - i + 1) * (max(mono.back().F, r[j]) - j + 1) << '\n';
            }

            if (p[i][j] >= 0)
            {
                while (!mono.empty() && mono.back().S <= p[i][j])
                    mono.pop_back();
                mono.emplace_back(pii(j + d, p[i][j]));
            }
        }
    }
    cout << ans << '\n';
}