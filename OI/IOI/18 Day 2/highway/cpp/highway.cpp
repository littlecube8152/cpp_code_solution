#include "highway.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

namespace
{
    int N, M, u, v;
    ll D;
    vector<pii> E[90000];
    int vis[90000], par[90000], dis[90000];
};

void find_pair(int N, vector<int> U, vector<int> V, int A, int B)
{
    ::N = N;
    ::M = U.size();
    D = ask(vector<int>(M, 0));
    int e = 0;
    {
        int L = 0, R = M - 1;
        while (L < R)
        {
            int mid = (L + R) / 2;
            vector<int> state(M, 0);
            for (int i = 0; i <= mid; i++)
                state[i] = 1;
            if (ask(state) > D)
                R = mid;
            else
                L = mid + 1;
        }
        u = U[L], v = V[L];
        e = L;
    }
    cerr << u << ' ' << v << '\n';
    for (int i = 0; i < M; i++)
        if (i != e)
            E[U[i]].emplace_back(pii(V[i], i)), E[V[i]].emplace_back(pii(U[i], i));

    vector<int> s = {u}, t = {v}, ontree(M, 1);
    ontree[e] = 0;
    queue<int> q;
    vis[u] = 1, vis[v] = 2;
    q.push(u);
    q.push(v);
    while (!q.empty())
    {
        auto i = q.front();
        q.pop();
        for (auto [j, k] : E[i])
            if(!vis[j])
            {
                vis[j] = vis[i];
                (vis[j] == 1 ? s : t).emplace_back(j);
                ontree[par[j] = k] = 0;
                dis[j] = dis[i] + 1;
                
                q.push(j);
            }
    }
    auto find = [&](vector<int> S)
    {
        sort(S.begin(), S.end(), [&](int i, int j)
             { return dis[i] < dis[j]; });
        int L = 0, R = S.size() - 1;
        while(L < R)
        {
            int mid = (L + R) / 2;
            vector<int> state = ontree;
            for (int i = mid + 1; i < S.size(); i++)
                state[par[S[i]]] = 1;
            if(ask(state) > D)
                L = mid + 1;
            else
                R = mid;
        }
        return S[L];
    };
    answer(find(s), find(t));
}
