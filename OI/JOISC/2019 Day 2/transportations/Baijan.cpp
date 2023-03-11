#include "Baijan.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

namespace
{
    int N;
    vector<int> receive, S, T, D;
}

void InitB(int N, int B, vector<int> S, vector<int> T, vector<int> D)
{
    ::N = N;
    ::S = S;
    ::T = T;
    ::D = D;
}

void ReceiveB(bool y)
{
    if (y)
    {
        vector<int> dis(N, 1'000'000'000);
        vector<pii> E[2000];
        dis[0] = 0;
        for (int i = 0; i < S.size(); i++)
        {
            E[S[i]].emplace_back(pii(T[i], D[i]));
            E[T[i]].emplace_back(pii(S[i], D[i]));
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(pii(0, 0));
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dis[u])
                continue;
            for (auto [v, w] : E[u])
                if (d + w < dis[v])
                {
                    dis[v] = d + w;
                    pq.push(pii(dis[v], v));
                }
        }
        for (int i = 0; i < N; i++)
            for (int p = 19; p >= 0; p--)
                SendB((dis[i] >> p) & 1);
    }
    else
    {
        for (int i = 0; i < S.size(); i++)
        {
            long long cur = S[i] * 2000LL * 500 + T[i] * 500 + D[i] - 1;
            for (int p = 31; p >= 0; p--)
                SendB((cur >> p) & 1);
        }
    }
}
