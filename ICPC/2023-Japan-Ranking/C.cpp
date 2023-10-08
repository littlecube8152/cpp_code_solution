#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, m, k;
ll dp[405][405], d[105][105], c[405][405], sum;
vector<pair<pii, ll>> E[105][105];
vector<pii> pos = {{-1, -1}};

auto dis = [](pii q) -> ll &
{ return d[q.F][q.S]; };
auto G = [](pii q) -> vector<pair<pii, ll>> &
{ return E[q.F][q.S]; };

void dijk(pii p)
{
    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            d[i][j] = 1e18;

    dis(p) = 0;
    pq.push(make_pair(dis(p), p));
    while (!pq.empty())
    {
        auto [cd, u] = pq.top();
        pq.pop();
        if (cd != dis(u))
            continue;
        for (auto [v, w] : G(u))
            if (dis(u) + w < dis(v))
            {
                dis(v) = dis(u) + w;
                pq.push(make_pair(dis(v), v));
            }
    }
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i < n; i++)
        for (int j = 1, w; j <= m; j++)
        {
            cin >> w;
            sum += w;
            E[i][j].emplace_back(make_pair(pii(i + 1, j), w));
            E[i + 1][j].emplace_back(make_pair(pii(i, j), w));
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1, w; j < m; j++)
        {
            cin >> w;
            sum += w;
            E[i][j].emplace_back(make_pair(pii(i, j + 1), w));
            E[i][j + 1].emplace_back(make_pair(pii(i, j), w));
        }
    k = 2 * (n + m - 4);
    for (int i = 2; i < n; i++)
        pos.emplace_back(pii(i, 1));
    for (int j = 2; j < m; j++)
        pos.emplace_back(pii(n, j));
    for (int i = n - 1; i >= 2; i--)
        pos.emplace_back(pii(i, m));
    for (int j = m - 1; j >= 2; j--)
        pos.emplace_back(pii(1, j));

    for (int i = 1; i <= k; i++)
    {
        dijk(pos[i]);
        for (int j = 1; j <= k; j++)
            c[i][j] = dis(pos[j]);
    }

    for (int l = 2; l <= k; l += 2)
        for (int i = 1; i + l - 1 <= k; i++)
        {
            int j = i + l - 1;
            dp[i][j] = c[i][j] + dp[i + 1][j - 1];
            for (int p = i + 1; p < j; p += 2)
                dp[i][j] = min(dp[i][j], dp[i][p] + dp[p + 1][j]);
        }
    cout << sum + dp[1][k] << '\n';
}