#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, W, M, Q, K, U, L, R, d[100005], o[100005], k[100005], z[100005], r[100005], b[100005], deg[100005], t[100005];
vector<int> E[100005], ord[100005], same[100005], topo, prod[100005], fr[100005], bc[100005];
map<int, int> mp;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> W;
    for (int i = 1; i <= N; i++)
    {
        cin >> d[i] >> k[i];
        ord[i].resize(k[i]);
        for (int &j : ord[i])
        {
            cin >> j;
            o[j] = i;
        }
    }
    for (int i = 1; i <= W; i++)
    {
        int Z;
        cin >> Z;
        if (mp[Z] == 0)
            mp[Z] = ++K;
        z[i] = mp[Z];
        same[z[i]].emplace_back(i);
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j < k[i]; j++)
            E[ord[i][j - 1]].emplace_back(ord[i][j]);

    for (int i = 1; i <= K; i++)
    {
        sort(same[i].begin(), same[i].end(), [&](int x, int y)
             { return d[o[x]] < d[o[y]]; });
        for (int j = 1; j < same[i].size(); j++)
        {
            // cerr << same[i][j - 1] << "->" << same[i][j] << '\n';
            E[same[i][j - 1]].emplace_back(same[i][j]);
        }
    }

    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> t[i];
        prod[i].resize(t[i]), fr[i].resize(t[i] + 1), bc[i].resize(t[i] + 1);
        for (int &j : prod[i])
        {
            cin >> j;
            o[j] = i;
        }
    }
    cin >> Q >> U >> L >> R;

    for (int i = 1; i <= M; i++)
        for (int j = 0; j + 1 < t[i]; j++)
            if (make_pair(i, j) != pii(U, L - 2) && make_pair(i, j) != pii(U, R - 1))
                E[prod[i][j]].emplace_back(prod[i][j + 1]);

    if (L > 1 && R < t[U])
        E[prod[U][L - 2]].emplace_back(prod[U][R]);

    for (int i = 1; i <= W; i++)
        for (int j : E[i])
            deg[j]++;
    queue<int> q;
    for (int i = 1; i <= W; i++)
        if (deg[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        topo.emplace_back(i);
        for (int j : E[i])
            if (--deg[j] == 0)
                q.push(j);
    }

    for (int i = L - 1; i < R; i++)
        r[prod[U][i]] = 1, b[prod[U][i]] = 1;
    for (int i : topo)
        for (int j : E[i])
            b[j] |= b[i];
    reverse(topo.begin(), topo.end());
    for (int i : topo)
        for (int j : E[i])
            r[i] |= r[j];
    // for (int i = 1; i <= W; i++)
    // cerr << ' ' << r[i] << ' ' << b[i] << '\n';
    for (int i = L - 1; i < R; i++)
        r[prod[U][i]] = 0, b[prod[U][i]] = 0;

    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j < t[i]; j++)
            fr[i][j + 1] = fr[i][j] | b[prod[i][j]];
        for (int j = t[i] - 1; j >= 0; j--)
            bc[i][j] = bc[i][j + 1] | r[prod[i][j]];
    }

    for (int i = 1; i <= Q; i++)
    {
        int u, p;
        cin >> u >> p;
        cout << (fr[u][p] || bc[u][p] ? "No\n" : "Yes\n");
    }
}