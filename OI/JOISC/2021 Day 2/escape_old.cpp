#include "escape_route.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define ll long long
using namespace std;
 
const ll inf = 1'000'000'000'000'000'000;
ll d1[90][90 * 90 + 5][90], d2[90][90], from[90];
vector<ll> tp[90];
vector<pll> last[90];
 
vector<pair<pii, ll>> dijkstra(int N, int r, int t, vector<pair<pii, ll>> edge, ll s)
{
    vector<pll> E[90];
    for (auto [e, w] : edge)
    {
        auto [u, v] = e;
        E[u].emplace_back(pll(v, w));
        E[v].emplace_back(pll(u, w));
    }
    edge.clear();
    for (int i = 0; i < N; i++)
        d1[r][t][i] = (i == r ? s : inf), from[i] = -1;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(pll(s, r));
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > d1[r][t][u])
            continue;
        for (auto [v, w] : E[u])
            if (d + w < d1[r][t][v])
            {
                d1[r][t][v] = d + w;
                from[v] = u;
                pq.push(pll(d1[r][t][v], v));
            }
    }
    for (int i = 0; i < N; i++)
        if (from[i] >= 0)
            edge.emplace_back(make_pair(i, from[i]), d1[r][t][i] - d1[r][t][from[i]]);
    return edge;
}
 
vector<ll> calculate_necessary_time(
    int N, int M, ll S, int Q,
    vector<int> A, vector<int> B, vector<ll> L, vector<ll> C, vector<int> U, vector<int> V, vector<ll> T)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            last[j].clear();
        for (int j = 0; j < M; j++)
        {
            last[A[j]].emplace_back(pll(C[j] - L[j], j));
            last[B[j]].emplace_back(pll(C[j] - L[j], j));
        }
        for (int j = 0; j < N; j++)
            sort(last[j].begin(), last[j].end());
 
        ll cur = S - 1, t = 0, nt = 0, nj = -1;
        bool update = 0, left = 0;
        vector<pair<pii, ll>> edge;
 
        do
        {
            // cerr << "do " << i << ' ' << cur << '\n';
            do
            {
                // cerr << "dijk\n";
                update = 0;
                edge = dijkstra(N, i, t, edge, cur);
                for (int j = 0; j < N; j++)
                    while (!last[j].empty() && d1[i][t][j] <= last[j].back().F)
                    {
                        int k = last[j].back().S;
                        // cerr << "add " << k << '\n';
                        edge.emplace_back(make_pair(pii(A[k], B[k]), L[k]));
                        update = 1;
                        last[j].pop_back();
                    }
            } while (update);
            // cerr << "done " << i << ' ' << cur << '\n';
            tp[i].emplace_back(cur);
            
            left = 0;
            nt = nj = -1;
            for (int j = 0; j < N; j++)
                if (!last[j].empty())
                    if (nt < cur - (d1[i][t][j] - last[j].back().F))
                    {
                        nt = cur - (d1[i][t][j] - last[j].back().F), nj = j;
                        left = 1;
                    }
 
            if (left)
            {
                ++t;
                cur = nt;
                int k = last[nj].back().S;
                edge.emplace_back(make_pair(pii(A[k], B[k]), L[k]));
                last[nj].pop_back();
            }
        } while (left);
    }
 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < tp[i].size(); j++)
        {
            cerr << i << " (time " << tp[i][j] << ") ";
            for (int k = 0; k < N; k++)
                cout << d1[i][j][k] << " \n"[k == N - 1];
        }
 
    vector<pair<int, pll>> E[90];
    for (int i = 0; i < M; i++)
    {
        E[A[i]].emplace_back(make_pair(B[i], pll(C[i], L[i])));
        E[B[i]].emplace_back(make_pair(A[i], pll(C[i], L[i])));
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            d2[i][j] = (i == j ? 0 : inf);
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push(pll(0, i));
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > d2[i][u])
                continue;
            for (auto [v, p] : E[u])
            {
                auto [c, l] = p;
                ll nd = (d % S <= c - l ? d : (d + S - 1) / S * S) + l;
                if (nd < d2[i][v])
                {
                    d2[i][v] = nd;
                    pq.push(pll(d2[i][v], v));
                }
            }
        }
    }
    // for (int i = 0; i < N; i++)
    //     for (int j = 0; j < N; j++)
    //         cerr << d2[i][j] << " \n"[j == N - 1];
    vector<ll> ans(Q);
    for (int i = 0; i < Q; i++)
    {
        int t = upper_bound(tp[U[i]].begin(), tp[U[i]].end(), T[i], greater<>()) - tp[U[i]].begin() - 1;
        ans[i] = inf;
        for (int j = 0; j < N; j++)
            if (d1[U[i]][t][j] < inf)
            {
                if (j == V[i])
                    ans[i] = min(ans[i], d1[U[i]][t][j] - tp[U[i]][t]);
                else
                    ans[i] = min(ans[i], S + d2[j][V[i]] - T[i]);
            }
        // cerr << ans[i] << '\n';
    }
    // cerr << '\n';
    return ans;
}

/*
0 (time 19) 19 1000000000000000000 1000000000000000000 1000000000000000000
0 (time 16) 16 19 1000000000000000000 1000000000000000000
0 (time 13) 13 16 1000000000000000000 1000000000000000000
0 (time 8) 8 11 15 16
0 (time 6) 6 9 8 9
0 (time 4) 4 7 6 7
1 (time 19) 1000000000000000000 19 1000000000000000000 1000000000000000000
1 (time 16) 19 16 1000000000000000000 1000000000000000000
1 (time 13) 16 13 1000000000000000000 1000000000000000000
1 (time 11) 14 11 15 16
1 (time 9) 12 9 13 14
1 (time 7) 10 7 11 12
1 (time 4) 7 4 8 9
1 (time 3) 6 3 7 8
1 (time 2) 5 2 6 7
2 (time 19) 1000000000000000000 1000000000000000000 19 1000000000000000000
2 (time 17) 1000000000000000000 1000000000000000000 17 18
2 (time 16) 1000000000000000000 1000000000000000000 16 17
2 (time 11) 18 15 11 12
2 (time 9) 16 13 9 10
2 (time 8) 15 12 8 9
2 (time 7) 14 11 7 8
2 (time 6) 8 10 6 7
2 (time 5) 7 9 5 6
2 (time 4) 6 8 4 5
3 (time 19) 1000000000000000000 1000000000000000000 1000000000000000000 19
3 (time 17) 1000000000000000000 1000000000000000000 18 17
3 (time 16) 1000000000000000000 1000000000000000000 17 16
3 (time 10) 18 15 11 10
3 (time 9) 17 14 10 9
3 (time 8) 16 13 9 8
3 (time 6) 14 11 7 6
3 (time 5) 8 10 6 5
3 (time 4) 7 9 5 4
3 (time 3) 6 8 4 3
*/