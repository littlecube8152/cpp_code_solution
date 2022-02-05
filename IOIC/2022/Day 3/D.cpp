#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, dsu[500005], rk[500005], val[500005], ans[500005];
pair<int, pii> E[1000005];

int find(int k)
{
    return k == dsu[k] ? k : dsu[k] = find(dsu[k]);
}

void merge(int x, int y)
{
    if (rk[x] <= rk[y])
    {
        dsu[x] = y;
        rk[y] += rk[x];
        val[y] = min(val[y], val[x]);
    }
    else
        merge(y, x);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        dsu[i] = val[i] = i, rk[i] = 1;
    for (int i = 1; i <= M; i++)
        cin >> E[i].S.F >> E[i].S.S >> E[i].F;
    sort(E + 1, E + 1 + M);
    for (int i = 1; i <= M; i++)
    {
        int rx = find(E[i].S.F), ry = find(E[i].S.S);
        if (rx != ry)
        {
            ans[max(val[rx], val[ry])] = E[i].F;
            merge(rx, ry);
        }
    }
    for (int i = 2; i <= N; i++)
        cout << ans[i] << '\n';
}