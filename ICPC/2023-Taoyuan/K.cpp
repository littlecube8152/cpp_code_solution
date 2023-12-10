#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 10015
using namespace std;

int n, m, k, p[N], s[N], t[N], thr[N], dsu[N], in[N], A[N], B[N], C[N];
vector<int> E[N];

int find(int k)
{
    return dsu[k] == k ? k : dsu[k] = find(dsu[k]);
}
void merge(int x, int y)
{
    x = find(x), y = find(y);
    if (y > x)
        swap(x, y);
    dsu[x] = y;
}

void calc(int *a, int *r)
{
    for (int i = 1; i <= n; i++)
        dsu[i] = i, in[i] = 0;
    for (int i = 1; i <= n; i++)
        if (a[i])
            thr[i] = 1e9;
        else
        {
            thr[i] = -1;
            for (auto j : E[i])
                if (a[j])
                    thr[i]++;
        }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!a[i] && thr[i] <= 0)
            q.push(i), in[i] = 1;
    while (!q.empty())
    {
        int u = q.front();
        // cerr << u << '\n';
        q.pop();
        for (auto v : E[u])
            if (a[v])
            {
                if (thr[v])
                    for (auto w : E[v])
                    {
                        thr[w]--;
                        if (thr[w] <= 0 && !in[w])
                        {
                            in[w] = 1;
                            q.push(w);
                        }
                    }
                merge(u, v);
                thr[v] = 0;
            }
            else 
            {
                if (thr[v] <= 0)
                    merge(u, v);
            }
    }
    for (int i = 1; i <= n; i++)
        r[i] = find(i);
}


void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        E[i].clear();
        s[i] = t[i] = C[i] = 0;
        dsu[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
        E[i].emplace_back(p[i]);
        E[p[i]].emplace_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int u;
        cin >> u;
        s[u]++;
    }
    for (int i = 1; i <= m; i++)
    {
        int u;
        cin >> u;
        t[u]++;
    }
    calc(s, A);
    calc(t, B);
    for (int i = 1; i <= n; i++)
    {
        C[A[i]] += s[i];
        C[B[i]] -= t[i];
        A[i] -= B[i];
    }
    bool ok = 1;
    for (int i = 1; i <= n; i++)
        ok &= (A[i] == 0 && C[i] == 0);
    cout << ok << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
}