#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define N 215
#define INF 1e9
#define all(x) x.begin(), x.end()
using namespace std;
struct hopcroftKarp
{
    bool dfs(int a, int L, vector<vector<int>> &g, vector<int> &btoa, vector<int> &A, vector<int> &B)
    {
        if (A[a] != L)
            return 0;
        A[a] = -1;
        for (int b : g[a])
            if (B[b] == L + 1)
            {
                B[b] = 0;
                if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
                    return btoa[b] = a, 1;
            }
        return 0;
    }

    int matching(vector<vector<int>> &g, vector<int> &btoa)
    {
        int res = 0;
        vector<int> A(g.size()), B(btoa.size()), cur, next;
        for (;;)
        {
            fill(all(A), 0);
            fill(all(B), 0);
            /// Find the starting nodes for BFS (i.e. layer 0).
            cur.clear();
            for (int a : btoa)
                if (a != -1)
                    A[a] = -1;
            for (int a = 0; a < g.size(); a++)
                if (A[a] == 0)
                    cur.push_back(a);
            /// Find all layers using bfs.
            for (int lay = 1;; lay++)
            {
                bool islast = 0;
                next.clear();
                for (int a : cur)
                    for (int b : g[a])
                    {
                        if (btoa[b] == -1)
                        {
                            B[b] = lay;
                            islast = 1;
                        }
                        else if (btoa[b] != a && !B[b])
                        {
                            B[b] = lay;
                            next.push_back(btoa[b]);
                        }
                    }
                if (islast)
                    break;
                if (next.empty())
                    return res;
                for (int a : next)
                    A[a] = lay;
                cur.swap(next);
            }
            /// Use DFS to scan for augmenting paths.
            for (int a = 0; a < g.size(); a++)
                res += dfs(a, 0, g, btoa, A, B);
        }
    }
} bipartie;

int n, m, dp[N][N][N];
vector<int> g1[N], g2[N];

bool match(int fa, int a, int b)
{
    int nn = g1[a].size(), mm = g2[b].size();
    vector<vector<int>> g(g1[a].size());
    if (nn - (fa != 0) < mm - (b != 1))
        return 0;
    if (mm == 1 && b != 1)
        return 1;
    for (int i = 0; i < nn; i++)
    {
        if (g1[a][i] == fa)
            continue;
        for (int j = 0; j < mm; j++)
        {
            if (dp[a][g1[a][i]][g2[b][j]] == 1)
                g[i].emplace_back(j);
        }
    }
    vector<int> btoa(g2[b].size(), -1);
    int flow = bipartie.matching(g, btoa);
    return flow == (mm - (b != 1));
}

vector<int> ord;

void dfs2(int p, int lp)
{
    for (auto i : g2[p])
    {
        if (i != lp)
            dfs2(i, p);
    }
    ord.emplace_back(p);
}

void dfs1(int p, int lp)
{
    for (auto i : g1[p])
    {
        if (i != lp)
            dfs1(i, p);
    }
    for (int j : ord)
    {
        if (dp[lp][p][j] != -1)
            continue;
        bool ans = match(lp, p, j);
        dp[lp][p][j] = ans;
        // cerr << lp << ' ' << p << ' ' << j << ' ' << dp[lp][p][j] << '\n';
    }
}
bool check(int root)
{
    // cerr << root << " -> \n";
    dfs1(root, 0);
    return dp[0][root][1];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g1[a].push_back(b);
        g1[b].push_back(a);
    }
    cin >> m;
    for (int i = 1; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g2[a].push_back(b);
        g2[b].push_back(a);
    }
    dfs2(1, 0);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= m; k++)
                dp[i][j][k] = -1;

    for (int i = 1; i <= n; i++)
    {
        if (check(i))
        {
            cout << "Y\n";
            return 0;
        }
    }
    cout << "N\n";
}