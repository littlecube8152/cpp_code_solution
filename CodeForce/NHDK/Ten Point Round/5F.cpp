#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    ll val = 0, w = 0, deg = 0, id = 0;
    bool valid = 1;
    vector<int> p;
};

int n, m;
ll r = 0;
Node node[200005];

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> node[i].w;
        node[i].id = i;
    }
    for (int i = 2; i <= n; i++)
        if (node[i].w > node[1].w)
            node[i].valid = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (node[x].valid && node[y].valid)
        {
            if (node[x].w > node[y].w)
            {
                node[y].p.emplace_back(y);
                node[y].deg++;
            }
            if (node[x].w < node[y].w)
            {
                node[y].p.emplace_back(x);
                node[x].deg++;
            }
        }
    }
    sort(node + 1, node + 1 + n, [](Node a, Node b) { return a.w > b.w; });
    int i = 1;
    for (; i <= n; i++)
        if (node[i].id == 1)
            break;
    for (; i <= n; i++)
    {
        for (int j : node[i].p)
            node[j].val = max(node[j].val, node[i].val + 1);
        if (node[i].id == n)
        {
            r = node[i].val;
            break;
        }
    }
    cout << ((r == 0) ? -1 : r) << '\n';
}