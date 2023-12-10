#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, m, w[55], s, t, in[55], out[55], dp[55], from[55];
vector<pii> E[55];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                char c;
                cin >> c;
            }
            cin >> w[i];
            dp[i] = -1;
            in[i] = out[i] = from[i] = 0;
            E[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            E[u].emplace_back(pii(v, w));
            out[u]++;
            in[v]++;
        }
        s = min_element(in, in + n) - in;
        t = min_element(out, out + n) - out;
        dp[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            dp[u] += w[u];
            for (auto [v, w] : E[u])
            {
                in[v]--;
                if (dp[u] + w == dp[v])
                    from[v] = -1;
                if (dp[u] + w > dp[v])
                    dp[v] = dp[u] + w, from[v] = u;
                if (in[v] == 0)
                    q.push(v);
            }
        }
        cout << dp[t];
        vector<int> sol;
        sol.emplace_back(t);
        while (sol.back() != s && sol.back() != -1)
            sol.emplace_back(from[sol.back()]);
        if (sol.back() == -1)
            cout << ",M\n";
        else
        {
            reverse(sol.begin(), sol.end());
            for (auto i : sol)
                cout << "," << i;
            cout << '\n';
        }
    }
}