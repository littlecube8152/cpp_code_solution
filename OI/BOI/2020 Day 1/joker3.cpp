#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define ll long long
using namespace std;

int T;
long long N, M, Q;
int dsu[200005], rk[200005], rev[200005];
int mxedge;
vector<pii> E;

pii Query(int k)
{
    if (k == dsu[k])
        return make_pair(k, rev[k]);
    else
    {
        pii p = Query(dsu[k]);
        if (rev[k])
            p.S ^= 1;
        return p;
    }
}

void Merge(int x, int y, int flip)
{
    if (rk[x] < rk[y])
    {
        dsu[x] = y;
        if (flip)
            rev[x] ^= 1;
        rk[y] += rk[x];
    }
    else
    {
        dsu[y] = x;
        if (flip)
            rev[y] ^= 1;
        rk[x] += rk[y];
    }
}

void solve()
{
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++)
        dsu[i] = i, rk[i] = 1;

    for (int i = 1; i <= M; i++)
    {
        int x, y;
        cin >> x >> y;
        E.emplace_back(make_pair(x, y));
    }

    mxedge = 0;
    for (int i = M - 1; i >= 1; i--)
    {
        pii edge = E[i];
        pii rx = Query(edge.F), ry = Query(edge.S);
        if (rx.F == ry.F)
        {
            if (rx.S == ry.S)
            {
                mxedge = i + 1;
                break;
            }
        }
        else
        {
            if (rx.S == ry.S)
                Merge(rx.F, ry.F, 1);
            else
                Merge(rx.F, ry.F, 0);
        }
    }
    for (int i = 1; i <= Q; i++)
    {
        int x, y;
        cin >> x >> y;
        if(y < mxedge)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    solve();
}