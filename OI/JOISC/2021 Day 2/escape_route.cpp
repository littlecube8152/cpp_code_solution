#include "escape_route.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define ll long long
using namespace std;

const ll inf = 100'000'000'000'000'000;
ll d1[90][90 * 90 + 5][90], d2[90][90], from[90];
vector<ll> tp[90];
vector<pll> last[90][90];

int getT(int i, ll t)
{
    return upper_bound(tp[i].begin(), tp[i].end(), t, greater<>()) - tp[i].begin() - 1;
}

void update(int N, int r, int t, int u, int v, ll w)
{
    int vt = getT(v, d1[r][t][u] + w);
    if (vt < 0)
        return;
    for (int i = 0; i < N; i++)
        d1[r][t][i] = min(d1[r][t][u] + w + d1[v][vt][i] - tp[v][vt], d1[r][t][i]);
}

pll calcNextEdge(int N, int r, ll T, int t)
{
    ll nt = -1, ni = -1, nj = -1;
    for (int i = 0; i < N; i++)
        if (!last[r][i].empty())
            if (nt < T - (d1[r][t][i] - last[r][i].back().F))
                nt = T - (d1[r][t][i] - last[r][i].back().F), ni = i;

    if (ni >= 0)
    {
        nj = last[r][ni].back().S;
        last[r][ni].pop_back();
    }
    return pll(nj, nt);
}

vector<ll> calculate_necessary_time(
    int N, int M, ll S, int Q,
    vector<int> A, vector<int> B, vector<ll> L, vector<ll> C, vector<int> U, vector<int> V, vector<ll> T)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            last[i][A[j]].emplace_back(pll(C[j] - L[j], j));
            last[i][B[j]].emplace_back(pll(C[j] - L[j], j));
        }
        for (int j = 0; j < N; j++)
            sort(last[i][j].begin(), last[i][j].end());
    }

    priority_queue<tuple<ll, int, int>> pq;
    for (int i = 0; i < N; i++)
    {
        tp[i].emplace_back(S - 1);
        for (int j = 0; j < N; j++)
            d1[i][0][j] = (i == j ? S - 1 : inf << 1);
        auto [j, nt] = calcNextEdge(N, i, tp[i].back(), (int)tp[i].size() - 1);
        if (nt >= 0)
            pq.push(make_tuple(nt, i, j));
    }

    while (!pq.empty())
    {
        auto [t, i, j] = pq.top();
        pq.pop();
        if (t < tp[i].back())
        {
            tp[i].emplace_back(t);
            int tt = (int)tp[i].size() - 1;
            for (int k = 0; k < N; k++)
                d1[i][tt][k] = d1[i][tt - 1][k] - (tp[i][tt - 1] - tp[i][tt]);
        }
        update(N, i, (int)tp[i].size() - 1, A[j], B[j], L[j]);
        update(N, i, (int)tp[i].size() - 1, B[j], A[j], L[j]);
        auto [k, nt] = calcNextEdge(N, i, tp[i].back(), (int)tp[i].size() - 1);
        if (nt >= 0)
            pq.push(make_tuple(nt, i, k));
    }

    // for (int i = 0; i < N; i++)
    //     for (int j = 0; j < tp[i].size(); j++)
    //     {
    //         cerr << i << " (time " << tp[i][j] << ") ";
    //         for (int k = 0; k < N; k++)
    //             cout << d1[i][j][k] << " \n"[k == N - 1];
    //     }

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
    }
    return ans;
}
