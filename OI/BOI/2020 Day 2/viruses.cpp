#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pliii tuple<ull, int, int, int>
#define F first
#define S second
using namespace std;

struct AhoCosarick
{
    int child[55][2] = {{}}, fail[55] = {}, jump[55][2] = {{}}, idx = 0, has[55] = {};
    void insert(int pos, vector<int> &s, int i = 0)
    {
        if (!child[i][s[pos]])
            child[i][s[pos]] = ++idx;
        if (pos + 1 < s.size())
            insert(pos + 1, s, child[i][s[pos]]);
        else
            has[child[i][s[pos]]] = 1;
    }
    void build_fail()
    {
        fail[0] = -1;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            for (int j = 0; j <= 1; j++)
            {
                if (child[i][j])
                    jump[i][j] = child[i][j];
                else if (fail[i] >= 0)
                    jump[i][j] = jump[fail[i]][j];
            }
            if (fail[i] >= 0)
                has[i] |= has[fail[i]];
            // cout << i << (has[i] ? '*' : ' ') << " -> " << jump[i][0] << ' ' << jump[i][1] << '\n';
            for (int j = 0; j <= 1; j++)
                if (child[i][j])
                {
                    int cur = fail[i];
                    while (cur >= 0)
                    {
                        if (child[cur][j])
                            break;
                        cur = fail[cur];
                    }
                    if (cur == -1)
                        fail[child[i][j]] = 0;
                    else
                        fail[child[i][j]] = child[cur][j];
                    q.push(child[i][j]);
                }
        }
    }
} ac;

int G, N, M, pG;
const ull inf = 1LL << 63;
ull dp[205][55][55];
vector<tuple<int, int, int>> tr[205];
priority_queue<pliii, vector<pliii>, greater<pliii>> pq;

signed main()
{
    cin >> G >> N >> M;
    pG = G;
    for (int i = 1; i <= N; i++)
    {
        int a, k;
        cin >> a >> k;
        vector<int> b(k);
        for (int j = 0; j < k; j++)
            cin >> b[j];

        while (b.size() >= 3)
        {
            int y = b.back();
            b.pop_back();
            int x = b.back();
            b.pop_back();
            tr[x].emplace_back(make_tuple(G, y, 1));
            tr[y].emplace_back(make_tuple(G, x, 2));
            b.emplace_back(G);
            G++;
        }

        if (b.size() == 1)
            tr[b[0]].emplace_back(make_tuple(a, -1, 0));
        else
        {
            tr[b[0]].emplace_back(make_tuple(a, b[1], 1));
            tr[b[1]].emplace_back(make_tuple(a, b[0], 2));
        }
    }
    for (int i = 1; i <= M; i++)
    {
        int l;
        cin >> l;
        vector<int> s(l);
        for (int j = 0; j < l; j++)
            cin >> s[j];
        ac.insert(0, s);
    }
    ac.build_fail();
    int L = ac.idx;
    for (int i = 0; i < G; i++)
        for (int j = 0; j <= L; j++)
            for (int k = 0; k <= L; k++)
                dp[i][j][k] = inf;
    for (int i = 0; i <= L; i++)
    {
        if (!ac.has[ac.jump[i][0]])
        {
            dp[0][i][ac.jump[i][0]] = 1;
            pq.push(make_tuple(1, 0, i, ac.jump[i][0]));
        }
        if (!ac.has[ac.jump[i][1]])
        {
            dp[1][i][ac.jump[i][1]] = 1;
            pq.push(make_tuple(1, 1, i, ac.jump[i][1]));
        }
    }
    while (!pq.empty())
    {
        auto [w, i, l, r] = pq.top();
        pq.pop();
        if (dp[i][l][r] < w)
            continue;
        for (auto [k, j, t] : tr[i])
            if (t == 0)
            {
                if (dp[k][l][r] > dp[i][l][r])
                {
                    dp[k][l][r] = dp[i][l][r];
                    pq.push(make_tuple(dp[k][l][r], k, l, r));
                }
            }
            else if (t == 1)
            {
                for (int e = 0; e <= L; e++)
                    if (dp[k][l][e] > dp[i][l][r] + dp[j][r][e])
                    {
                        dp[k][l][e] = dp[i][l][r] + dp[j][r][e];
                        pq.push(make_tuple(dp[k][l][e], k, l, e));
                    }
            }
            else if (t == 2)
            {
                for (int s = 0; s <= L; s++)
                    if (dp[k][s][r] > dp[j][s][l] + dp[i][l][r])
                    {
                        dp[k][s][r] = dp[j][s][l] + dp[i][l][r];
                        pq.push(make_tuple(dp[k][s][r], k, s, r));
                    }
            }
    }

    for (int i = 2; i < pG; i++)
    {
        ull ans = inf;
        for (int j = 0; j <= L; j++)
            ans = min(ans, dp[i][0][j]);
        if (ans >= inf)
            cout << "YES\n";
        else
            cout << "NO " << ans << '\n';
    }
}
