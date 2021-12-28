#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, dsu[1005], x, y, rx, ry;
vector<pii> oe;
vector<int> ne;

int find(int k)
{
    while (k != dsu[k])
        k = dsu[k];
    return k;
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        dsu[i] = i;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        rx = find(x), ry = find(y);
        if (find(x) == find(y))
            oe.emplace_back(make_pair(x, y));
        else
            dsu[ry] = rx;
    }
    for (int i = 1; i <= n; i++)
        if (dsu[i] == i)
            ne.emplace_back(i);
    cout << oe.size() << '\n';
    for (auto i : oe)
    {
        cout << i.F << " " << i.S << " " << ne.back() << " " << *ne.begin() << '\n';
        ne.pop_back();
    }
}