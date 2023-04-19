#include "Baijan.h"
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
            SendB((message >> i) & 1);
    }

    void calcNext()
    {
        cerr << "calcNextB " << u << ' ' << ld << '\n';
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
                u = pq.top().S, dA = 0, dB = d[u] - ld;
            else
                u = 0, dA = 0, dB = 511;
            send(dB, 9);
            phase = 1;
        }
    }

    void check_distance()
    {
        for (int b = 0; b < 9; b++)
            dA = dA * 2 + receive[b];
        receive.clear();
        if (dA <= dB)
            phase = 2;
        else
        {
            send(u, 11);
            ld += dB;
            calcNext();
        }
    }

    void update_distance()
    {
        u = 0;
        ld += dA;
        for (int b = 0; b < 11; b++)
            u = u * 2 + receive[b];
        receive.clear();
        calcNext();
    }
}

void InitB(int N, int B, vector<int> S, vector<int> T, vector<int> D)
{
    ::N = N;
    ::T = N;
    for (int i = 1; i < N; i++)
        d[i] = 1'000'000'000;
    for (int i = 0; i < B; i++)
    {
        E[S[i]].emplace_back(pii(T[i], D[i]));
        E[T[i]].emplace_back(pii(S[i], D[i]));
    }
    calcNext();
}

void ReceiveB(bool y)
{
    receive.emplace_back(y);
    if (receive.size() == 9 && phase == 1)
        check_distance();
    if (receive.size() == 11 && phase == 2)
        update_distance();
}
