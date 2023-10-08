#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int N, M, K, Q, P, scc[2400006], vis[2400006], e[2400006];
pii E[5600006], R[5600006];
vector<int> order;
int station(int i)
{
    return i * 2;
}

int power(int i, int r)
{
    return (i * 2 - 1 + r + N) * 2;
}

#define NOT 1 ^

void build(int x, int y)
{
    E[P + 1] = pii(NOT x, y);
    E[P + 2] = pii(NOT y, x);
    R[P + 1] = pii(x, NOT y);
    R[P + 2] = pii(y, NOT x);
    P += 2;
}

void dfs(int u)
{
    vis[u] = 1;
    for (int i = e[u - 1]; i < e[u]; i++)
    {
        int v = E[i].S;
        if (!vis[v])
            dfs(v);
    }
    order.emplace_back(u);
}

void dfscc(int u, int r)
{
    scc[u] = r;
    for (int i = e[u - 1]; i < e[u]; i++)
    {
        int v = R[i].S;
        if (!scc[v])
            dfscc(v, r);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> K >> N >> M >> Q;
    // build powers
    for (int i = 1; i < M; i++)
    {
        build(power(i, 0), NOT power(i + 1, 0));
        build(NOT power(i, 1), power(i + 1, 1));
        build(NOT power(i, 1), NOT power(i + 1, 0));
    }
    // build or
    for (int i = 1; i <= K; i++)
    {
        int x, y;
        cin >> x >> y;
        build(station(x), station(y));
    }
    // build range
    for (int i = 1; i <= N; i++)
    {
        int l, r;
        cin >> l >> r;
        build(NOT station(i), power(l, 0));
        build(NOT station(i), power(r, 1));
    }
    // build interfere
    for (int i = 1; i <= Q; i++)
    {
        int u, v;
        cin >> u >> v;
        build(NOT station(u), NOT station(v));
    }

    sort(E + 1, E + 1 + P);
    e[0] = 1;
    for (int i = 1, j = 1; i <= 2 * N + 4 * M + 1; i++)
    {
        while (j <= P && E[j].F == i)
            j++;
        e[i] = j;
    }

    for (int i = 1; i <= 2 * N + 4 * M + 1; i++)
        if (!vis[i])
            dfs(i);

    reverse(order.begin(), order.end());
    sort(R + 1, R + 1 + P);
    for (int i = 1, j = 1; i <= 2 * N + 4 * M + 1; i++)
    {
        while (j <= P && R[j].F == i)
            j++;
        e[i] = j;
    }

    int k = 0;
    for (int i : order)
        if (!scc[i])
            dfscc(i, ++k);
    for (int i = 1; i <= 2 * N + 4 * M + 1; i += 2)
        if (scc[i] == scc[NOT i])
        {
            cout << -1 << '\n';
            return 0;
        }

    int f = 0;
    vector<int> sol;
    // for (int i = 1; i <= M; i++)
    // {
    //     cout << ' ' << (scc[power(i, 0)] > scc[NOT power(i, 0)]) << ' ' << (scc[power(i, 1)] > scc[NOT power(i, 1)]) << '\n';
    // }
    for (int i = 1; i <= M; i++)
        if (scc[power(i, 0)] > scc[NOT power(i, 0)])
            f = i;
    for (int i = 1; i <= N; i++)
        if (scc[station(i)] > scc[NOT station(i)])
            sol.emplace_back(i);
    cout << sol.size() << ' ' << f << '\n';
    for (auto i : sol)
        cout << i << ' ';
    cout << '\n';
}