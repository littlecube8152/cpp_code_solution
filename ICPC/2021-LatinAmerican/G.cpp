#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define F first
#define S second
using namespace std;

int N, K[200005], root[200005], pre[400005], vis[400005], sz[400005], acc;
vector<int> E[400005];
vector<int> in;
unordered_map<ull, ull> mp;
map<pull, int> trees;
mt19937 rd(49);
bool valid;
pull g;

ull get_hash(int u, int reset)
{
    ull h = 0;
    vis[u] = 0;
    for (auto v : E[u])
        if (vis[v] == 2)
            h += get_hash(v, reset);
    while (!mp[h])
        mp[h] = rd();
    vis[u] = reset;
    return mp[h];
}

void dfs(int u, int k)
{
    vis[u] = 1;
    sz[u] = 1;
    for (auto v : E[u])
        if (!vis[v])
        {
            pre[v] = u;
            dfs(v, k);
            sz[u] += sz[v];
        }
    vis[u] = 2;
    in.emplace_back(u);
    if (sz[u] > k)
        valid = false;
    if (sz[u] == k)
    {
        vector<int> c;
        for (int t = 1; t <= k; t++)
        {
            int i = in.back();
            in.pop_back();
            bool is = k - sz[i] <= k / 2;
            for (auto j : E[i])
                if (vis[j] == 2)
                    if (sz[j] > k / 2 && j != pre[i])
                        is = false;
            if (is)
                c.emplace_back(i);
        }
        assert(c.size() <= 2);
        c.resize(2, c[0]);
        pull h;
        h.F = get_hash(c[0], 2);
        h.S = get_hash(c[1], 1);
        if (h.F > h.S)
            swap(h.F, h.S);
        if (g == pull(0, 0) || g == h)
            g = h;
        else
            valid = false;
        sz[u] = 0;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> K[i];
        root[i] = acc + 1;
        for (int j = 1; j < K[i]; j++)
        {
            int u, v;
            cin >> u >> v;
            u += acc, v += acc;
            E[u].emplace_back(v);
            E[v].emplace_back(u);
        }
        g = pull(0, 0);
        in.clear();
        valid = true;
        dfs(root[i], K[i]);
        trees[g]++;
        acc += K[i];
    }
    for (int i = 1; i <= N; i++)
    {
        int ans = -1;
        for (int j = 1; j <= K[i]; j++)
            if (K[i] % j == 0)
            {
                for (int k = root[i]; k <= root[i] + K[i] - 1; k++)
                    vis[k] = 0;
                g = pull(0, 0);
                valid = true;
                in.clear();
                dfs(root[i], j);
                if (valid)
                    ans += trees[g];
            }
        cout << ans << " \n"[i == N];
    }
}
