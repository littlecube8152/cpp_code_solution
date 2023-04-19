#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, dsu[1005], inv[1005];

pii find(int k)
{
    if (k == dsu[k])
        return {k, inv[k]};
    else
    {
        pii p = find(dsu[k]);
        inv[k] ^= inv[dsu[k]];
        dsu[k] = p.F;
        return {p.F, inv[k]};
    }
}

void merge(int x, int y, bool i)
{
    dsu[x] = y;
    inv[x] ^= i;
}

signed main()
{
     ifstream cin("truth.in");
     ofstream cout("truth.out");
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        dsu[i] = i;
    for (int i = 1; i <= M; i++)
    {
        int u, v, r;
        pii pu, pv;
        char c;
        cin >> u >> v >> c;
        r = (c == 'T' ? 0 : 1);
        pu = find(u), pv = find(v);
        if (pu.F == pv.F && (pu.S ^ pv.S) != r)
        {
            cout << i - 1 << '\n';
            return 0;
        }
        if (pu.F != pv.F)
            merge(pu.F, pv.F, (pu.S ^ pv.S) != r);
    }
    cout << M << '\n';
}