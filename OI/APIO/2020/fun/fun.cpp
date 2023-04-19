#include "fun.h"
#ifndef EVAL
#include "grader.cpp"
#endif
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

vector<int> createFunTour(int N, int Q)
{
    if (N == 2)
        return {0, 1};
    priority_queue<pii> pq;
    for (int i = 1; i < N; i++)
        pq.push(pii(attractionsBehind(0, i), i)); // N - 1
    int c = 0;
    while (!pq.empty() && pq.top().F > N / 2)
    {
        auto [sz, u] = pq.top();
        pq.pop();
        c = u;
    }
    vector<int> d(N), order(N), sol(2 * N, -1), large(2 * N, 0);
    vector<int> tmp[2];
    for (int i = 0; i < N; i++)
    {
        if (i != c)
            d[i] = hoursRequired(c, i); // N - 1
        order[i] = i;
    }
    sort(order.begin(), order.end(), [&](int i, int j)
         { return d[i] > d[j]; });

    auto diffSubtree = [&](int i, int j)
    {
        if (i == c || j == c)
            return true;
        return hoursRequired(i, j) == d[i] + d[j];
    };

    int t = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (tmp[t ^ 1].empty() || diffSubtree(order[i], tmp[t ^ 1].back()))
        {
            tmp[t].emplace_back(order[i]);
            if (tmp[t].size() + t > tmp[t ^ 1].size())
                t ^= 1;
        }
        else
            tmp[t ^ 1].emplace_back(order[i]);
    }

    for (int i = 0; i < tmp[0].size(); i++)
        sol[i * 2] = tmp[0][i];
    for (int i = 0; i < tmp[1].size(); i++)
        sol[i * 2 + 1] = tmp[1][i];

    tmp[0].clear(), tmp[1].clear();
    int over = -1, in = 0, out = 0, last = 2 * N;
    for (int i = 2 * N - 1; i > 0; i--)
        if (sol[i] == -1 && sol[i - 1] >= 0)
        {
            over = sol[i - 1];
            break;
        }
    for (int i = 0; i < 2 * N; i++)
        if (sol[i] >= 0)
        {
            if (!diffSubtree(sol[i], over))
                large[i] = 1;
            (large[i] ? in : out)++;
        }

    for (int i = 0; i < 2 * N; i++)
    {
        if (in >= out)
        {
            last = i;
            break;
        }
        (large[i] ? in : out)--;
    }

    for (int i = last; i < 2 * N; i++)
        if (sol[i] >= 0)
            tmp[large[i]].emplace_back(sol[i]);

    sort(tmp[0].begin(), tmp[0].end(), [&](int i, int j)
         { return d[i] > d[j]; });
    sort(tmp[1].begin(), tmp[1].end(), [&](int i, int j)
         { return d[i] > d[j]; });

    // x, y, b, a valid
    {
        int a = tmp[1].front(), b = tmp[0].front();
        if ((last < 1 || diffSubtree(sol[last - 1], b)) && // y, b different
            (last < 2 || d[b] <= d[sol[last - 2]]) &&      // x >= b
            (last < 1 || d[a] <= d[sol[last - 1]]))        // x <= b;
            swap(tmp[0], tmp[1]);
    }

    for (int i = last; i < 2 * N; i++)
        sol[i] = -1;

    for (int i = 0; i < tmp[1].size(); i++)
        sol[last + i * 2] = tmp[1][i];
    for (int i = 0; i < tmp[0].size(); i++)
        sol[last + i * 2 + 1] = tmp[0][i];

    int off = 0;
    for (int i = 0; i < 2 * N; i++)
        if (sol[i] == -1)
            off++;
        else
            sol[i - off] = sol[i];
    sol.resize(N);
    sol[N - 1] = c;
    return sol;
}