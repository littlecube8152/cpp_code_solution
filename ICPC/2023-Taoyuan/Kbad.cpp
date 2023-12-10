#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define x first
#define y second
#define N 10015
using namespace std;

int n, m, k, p[N], s[N], t[N], d[N], vis[N], on[N], has[N], ban[N], shit[N];
vector<int> E[N], one[N], two[N];
void dfs(int u)
{
    vis[u] = 1;
    for (auto v : E[u])
        if (!vis[v])
        {
            p[v] = u;
            d[v] = d[u] + 1;
            dfs(v);
        }
    vis[u] = 0;
}

void solve()
{
#define WA()           \
    cout << 0 << '\n'; \
    return;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        E[i].clear();
        one[i].clear();
        two[i].clear();
        on[i] = s[i] = ban[i] = t[i] = has[i] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
        E[i].emplace_back(p[i]);
        E[p[i]].emplace_back(i);
    }
    vector<int> c;
    {
        d[1] = p[1] = 0;
        dfs(1);
        int a = max_element(d + 1, d + n + 1) - d;
        dfs(a);
        c.emplace_back(max_element(d + 1, d + n + 1) - d);
        while (c.back() != a)
            c.emplace_back(p[c.back()]);
        reverse(c.begin(), c.end());
        for (int i : c)
            on[i] = 1;
    }

    for (int i = 1; i <= n; i++)
        if (on[i])
            continue;
        else if (on[p[i]])
            one[p[i]].emplace_back(i);
        else
            two[p[i]].emplace_back(i);

    for (int i = 1; i <= m; i++)
    {
        int u;
        cin >> u;
        s[u] = 1;
    }
    for (int j = 1; j <= m; j++)
    {
        int u;
        cin >> u;
        t[u] = 1;
    }

    k = c.size();
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        bool same = 1;
        for (int j : one[i])
            if (two[j].empty())
                sum += s[j], same &= (s[j] == t[j]);
        has[i] = sum;
        if (sum >= 2 && !same)
            WA();
        if (sum >= 2)
            ban[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        bool same = 1;
        for (int j : two[i])
            sum += s[j], same &= (s[j] == t[j]);
        if (sum >= 2 && !same)
            WA();
        if (sum >= 2)
            ban[i] = 1;
    }

    for (int i = 1; i <= n; i++)
        for (int j : E[i])
            shit[i] += s[j];

    for (int i = 0; i < k; i++)
    {
        int j = i + 1;
        while (j < k && !ban[j])
            j++;
        // [i, j)
        // if stem is not movable
        bool fuck = 0;
        for (int p = i; p < j; p++)
        {
            int u = c[p];
            for (auto v : E[u])
                if (shit[v] == 1)
                    fuck = 1;
        }
        if (!fuck)
        {
            for (int p = i; p < j; p++)
            {
                int u = c[p];
                if (s[u] != t[u])
                    WA();
                for (int v : one[u])
                {
                    int allsum = s[v] - t[v], diff2 = 0;
                    for (int w : two[v])
                    {    
                        allsum += s[w] - t[w];
                        if (s[w] != t[w])
                            diff2++;
                    }
                    if (allsum != 0)
                        WA();
                    if (diff2 && s[u])
                        WA();
                }
            }
        }
        else 
        {
            int compress = 0;
            for (int p = i; p < j; p++)
            {
                int u = c[p];
                // case 1: u is end
                if (t[u])
                {
                    
                }
            }
        }
        i = j;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    while (T--)
        solve();
}