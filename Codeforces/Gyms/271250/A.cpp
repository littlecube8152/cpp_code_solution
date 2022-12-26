#include <bits/stdc++.h>
using namespace std;

vector<int> e[2000005];
int n, m, dsu[2000005], size[2000005], tree;

int find(int n)
{
    while (dsu[n] != n)
        n = dsu[n];
    return n;
}

void merge(int a, int b)
{
    if (size[a] > size[b])
        dsu[b] = a, size[a] += size[b];
    else
        dsu[a] = b, size[b] += size[a];
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        dsu[i] = i, size[i] = 1;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x != y)
            e[max(x, y)].emplace_back(min(x, y));
    }
    for (int i = 0; i < n; i++)
    {
        tree++;
        for (int j : e[i])
        {
            int ri = find(i), rj = find(j);
            if (ri != rj)
                merge(ri, rj), tree--;
        }
        //cout << tree << '\n';   
        if (tree == 1)
            cout << 1;
        else
            cout << 0;
    }
    cout << '\n';
}