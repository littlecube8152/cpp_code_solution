#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll N, M, p[100005], dsu[100005], rk[100005];
pair<int, pii> edge[100005];

void merge(int x, int y)
{
    if (rk[y] <= rk[x])
    {
        rk[x] += rk[y];
        dsu[y] = x;
    }
    else
        merge(y, x);
}

int find(int x)
{
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

signed main()
{
    fast;
    ifstream cin("wormsort.in");
    ofstream cout("wormsort.out");
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> p[i];
    for (int i = 1; i <= M; i++)
        cin >> edge[i].S.F >> edge[i].S.S >> edge[i].F;
    ll L = 1, R = 2e9;
    while (L < R)
    {
        ll mid = (L + R + 1) / 2;
        for (int i = 1; i <= N; i++)
            dsu[i] = i, rk[i] = 1;
        for (int i = 1; i <= M; i++)
            if (edge[i].F >= mid)
            {
                int rx = find(edge[i].S.F), ry = find(edge[i].S.S);
                if (rx != ry)
                    merge(rx, ry);
            }
        bool valid = true;
        for (int i = 1; i <= N; i++)
            if (find(i) != find(p[i]))
                valid = false;
        if (valid)
            L = mid;
        else
            R = mid - 1;
    }
    cout << (L > 1e9 ? -1 : L) << '\n';
}