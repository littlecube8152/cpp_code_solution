#include "Azer.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

namespace
{
    int N;
    bool state;
    vector<int> receive, U, V, C;
} // namespace

void InitA(int N, int A, vector<int> U, vector<int> V, vector<int> C)
{
    ::N = N;
    ::U = U;
    ::V = V;
    ::C = C;
    SendA(state = U.empty());
}

void ReceiveA(bool x)
{
    receive.emplace_back(x);
}

std::vector<int> Answer()
{
    vector<int> ans(N);
    if (state)
    {
        for (int i = 0; i < N; i++)
            for (int p = 0; p < 20; p++)
                ans[i] = ans[i] * 2 + receive[i * 20 + p];
    }
    else
    {
        for (int i = 0; i < receive.size() / 32; i++)
        {
            long long cur = 0;
            for (int p = 0; p < 32; p++)
                cur = cur * 2 + receive[i * 32 + p];
            // cerr << i << ' ' << (cur / 500 / 2000) << ' ' << (cur / 500 % 2000) << ' ' << (cur % 500 + 1) << '\n';
            U.emplace_back(cur / 500 / 2000);
            V.emplace_back(cur / 500 % 2000);
            C.emplace_back(cur % 500 + 1);
        }

        vector<int> dis(N, 1'000'000'000);
        vector<pii> E[2000];
        dis[0] = 0;
        for (int i = 0; i < U.size(); i++)
        {
            E[U[i]].emplace_back(pii(V[i], C[i]));
            E[V[i]].emplace_back(pii(U[i], C[i]));
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
        ans = dis;
    }
    return ans;
}
