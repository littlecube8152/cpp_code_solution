#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, color[25], ans;
pii E[25];
vector<int> sol;

int dsu[25], ccnt[25];
int find(int k)
{
    return dsu[k] == k ? k : dsu[k] = find(dsu[k]);
}

void solve(int mask)
{
    int res = 0;
    for (int i = 1; i <= N; i++)
        dsu[i] = i;
    for (int i = 1; i <= M; i++)
        ccnt[i] = 0;
    for (int i = 0; i < M; i++)
        if ((mask >> i) & 1)
        {
            int rx = find(E[i].F), ry = find(E[i].S);
            if (rx == ry)
                return;
            dsu[rx] = ry;
            ccnt[color[i]] = 1;
        }
    for (int i = 1; i <= M; i++)
        res += ccnt[i];
    if (res > ans)
    {
        ans = res;
        sol.clear();
        for (int i = 0; i < M; i++)
            if ((mask >> i) & 1)
                sol.emplace_back(i + 1);
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> E[i].F >> E[i].S >> color[i];
    for (int i = 1; i < (1 << M); i++)
        if (__builtin_popcount(i) == N - 1)
            solve(i);
    cout << ans << '\n';
    for (int i = 0; i < N - 1; i++)
        cout << sol[i] << " \n"[i == N - 2];
}
