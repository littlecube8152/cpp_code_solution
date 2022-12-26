#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, T, dsu[1500005], rk[1500005], ans[1500005], cur[1500005], clan[1500005], head[500005], idx, h;

void merge(int x, int y, int p)
{
    if (rk[x] <= rk[y])
    {
        dsu[x] = y;
        rk[y] += rk[x];
        ans[y] += ans[x];
        head[p] = y;
        clan[y] = p;
    }
    else
        merge(y, x, p);
}

pii find(int k)
{
    if (k == dsu[k])
        return pii{k, clan[k]};
    else
    {
        pii res = find(dsu[k]);
        dsu[k] = res.F;
        return res;
    }
}

signed main()
{
    // ios::sync_with_stdio(0), cin.tie(0);
    cin >> h >> h >> h >> h >> h;
    cin >> N >> T;
    for (int i = 1; i <= 1500000; i++)
        dsu[i] = i, rk[i] = 1;
    for (int i = 1; i <= N; i++)
        head[i] = i, clan[i] = i;
    idx = N;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        cur[i] = ++idx;
        ans[idx] = 1;
        merge(cur[i], head[a], a);
    }
    for (int i = 1; i <= T; i++)
    {
        int t, x, y, p, np, cx, cy, rx, ry;
        cin >> t;
        if (t == 1)
        {
            cin >> x >> y;
            cx = cur[x];
            cy = cur[y]; 
            tie(rx, np) = find(cx);
            tie(ry, p) = find(cy);
            if (rx != ry)
            {
                merge(rx, ry, p);
                head[np] = ++idx;
                clan[idx] = np;
            }
        }
        else if (t == 2)
        {
            cin >> x >> y;
            cx = cur[x];
            cy = cur[y];
            rx = find(cx).F;
            ans[rx]--;
            cur[x] = ++idx;
            cx = idx;
            ans[cx] = 1;
            tie(ry, p) = find(cy);
            merge(cx, ry, p);
        }
        else if (t == 3)
        {
            cin >> x >> p;
            cx = cur[x];
            ry = head[p];
            rx = find(cx).F;
            ans[rx]--;
            cur[x] = ++idx;
            cx = idx;
            ans[cx] = 1;
            merge(cx, ry, p);
        }
        else if (t == 4)
        {
            cin >> x;
            cx = cur[x];
            rx = find(cx).F;
            cout << clan[rx] << " " << ans[rx] << '\n';
        }
        else if (t == 5)
        {
            cin >> p;
            cout << ans[head[p]] << '\n';
        }
    }
    for (int i = 1; i <= N; i++)
        cout << find(cur[i]).S << " \n"[i == N];
}

/*
1 1 1 1 1
4 100
1 3 1 4
5 2
1 3 4
4 4
2 4 2
5 4
3 2 1
4 1
5 1
2 3 1
3 4 3*/