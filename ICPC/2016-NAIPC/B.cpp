#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

string s;
int N, pre[4000], l[4000], r[4000], len[100000];
pii sol[4000];
vector<int> E[4000];

bool invalid = true;
int dfs(int u, int start)
{
    start += l[u] + r[u] + 2;
    if (len[start] > l[u])
        l[u]++, invalid = true;
    sol[u].F = start;
    for (auto v : E[u])
        start = dfs(v, start);
    if (len[start] > r[u])
        r[u]++, invalid = true;
    return sol[u].S = start;
}

void output(int u)
{
    cout << sol[u].F << ',' << sol[u].S << ':';
    for (auto v : E[u])
        output(v);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int i = 0; i < 100000; i++)
        len[i] = (i <= 9 ? 1 : len[i / 10] + 1);
    cin >> s;
    vector<int> v = {0};
    for (auto c : s)
        if (c == '(')
            E[v.back()].emplace_back(++N), pre[N] = v.back(), v.emplace_back(N);
        else
            v.pop_back();

    while (invalid)
    {
        invalid = false;
        int start = 0;
        for (auto u : E[0])
            start = dfs(u, start);
    }

    for (auto u : E[0])
        output(u);
    cout << '\n';
}
