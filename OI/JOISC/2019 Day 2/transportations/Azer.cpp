#include "Azer.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

namespace
{
    int N, d[2000] = {}, cnt = 0, ld = 0, u = 0, T, dA, dB;
    int phase; // 1: receive distance, 2: receive node
    bool vis[2000] = {};
    vector<pii> E[2000];
    vector<int> receive;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    void send(int message, int bit)
    {
        for (int i = bit - 1; i >= 0; i--)
            SendA((message >> i) & 1);
    }

    void calcNext()
    {
        cerr << "calcNextA " << u << ' ' << ld << '\n';
        T--;
        vis[u] = 1;
        d[u] = ld;
        for (auto [v, w] : E[u])
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                pq.push(pii(d[v], v));
            }
        if (T)
        {
            while (!pq.empty() && vis[pq.top().S])
                pq.pop();
            if (!pq.empty())
                u = pq.top().S, dA = d[u] - ld, dB = 0;
            else
                u = 0, dA = 511, dB = 0;
            send(dA, 9);
            phase = 1;
        }
    }

    void check_distance()
    {
        for (int b = 0; b < 9; b++)
            dB = dB * 2 + receive[b];
        receive.clear();
        if (dB < dA)
            phase = 2;
        else
        {
            send(u, 11);
            ld += dA;
            calcNext();
        }
    }

    void update_distance()
    {
        u = 0;
        ld += dB;
        for (int b = 0; b < 11; b++)
            u = u * 2 + receive[b];
        receive.clear();
        calcNext();
    }

}

void InitA(int N, int A, vector<int> U, vector<int> V, vector<int> C)
{
    ::N = N;
    ::T = N;
    for (int i = 1; i < N; i++)
        d[i] = 1'000'000'000;
    for (int i = 0; i < A; i++)
    {
        E[U[i]].emplace_back(pii(V[i], C[i]));
        E[V[i]].emplace_back(pii(U[i], C[i]));
    }
    calcNext();
}

void ReceiveA(bool x)
{
    receive.emplace_back(x);
    if (receive.size() == 9 && phase == 1)
        check_distance();
    if (receive.size() == 11 && phase == 2)
        update_distance();
}

std::vector<int> Answer()
{
    vector<int> ans(N);
    for (int i = 0; i < N; i++)
        ans[i] = d[i];
    return ans;
}
