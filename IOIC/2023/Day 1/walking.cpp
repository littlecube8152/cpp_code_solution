// #include "lib0149.h"
#include <bits/stdc++.h>
using namespace std;

int vis[30000], dep[30000];
vector<int> E[30000];

std::string Danbing(int N, int M, std::vector<int> U, std::vector<int> V, int B)
{
    for (int i = 0; i < M; i++)
    {
        E[U[i]].emplace_back(V[i]);
        E[V[i]].emplace_back(U[i]);
    }
    vis[B] = 1;
    queue<int> q;
    q.push(B);

    dep[B] = N;
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (int i : E[k])
            if (!vis[i])
            {
                dep[i] = dep[k] - 1;
                vis[i] = 1;
                q.push(i);
            }
    }

    string s;
    for (int i = 1; i <= N; i += 3)
    {
        // cerr << dep[i] << ' ' << dep[i + 1] << ' ' << dep[i + 2] << '\n';
        int d = (dep[i] % 5) + 5 * (dep[i + 1] % 5) + 25 * (dep[i + 2] % 5);
        for (int j = 0; j < 7; j++)
            s.push_back((d & (1 << j)) ? '1' : '0');
    }
    return s;
}

void Ziskinit(std::string S)
{
    int N = S.size() / 7 * 3;
    for (int i = 1; i <= N; i += 3)
    {
        int d = 0;
        for (int j = 0; j < 7; j++)
            d += (S[i / 3 * 7 + j] - '0') * (1 << j);
        dep[i] = d % 5;
        dep[i + 1] = d / 5 % 5;
        dep[i + 2] = d / 25 % 5;
        // cerr << dep[i] << ' ' << dep[i + 1] << ' ' << dep[i + 2] << '\n';
    }
}

int Zisking(int N, std::vector<int> adj)
{
    int exist[5] = {};
    for (auto i : adj)
    {
        exist[dep[i]] = i;
        //cout << i << ' ' << dep[i] << '\n';
    }
    //cout << '\n';
    for (int i = 0; i < 5; i++)
        if (exist[i] && exist[(i + 2) % 5])
            return exist[(i + 2) % 5];
    for (int i = 0; i < 5; i++)
        if (exist[i] && exist[(i + 1) % 5])
            return exist[(i + 1) % 5];
    for (int i = 0; i < 5; i++)
        if (exist[i])
            return exist[i];
}