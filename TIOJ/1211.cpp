#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, dsu[10005];
struct edge
{
    int w, x, y;
    edge(int w, int x, int y) : w(w), x(x), y(y) {}
};
inline bool operator<(const edge &e1, const edge &e2)
{
    if (e1.w != e2.w)
        return e1.w < e2.w;
    if (e1.x != e2.x)
        return e1.x < e2.x;
    return e1.y < e2.y;
}

inline int find(int n)
{
    if (dsu[n] == n)
        return n;
    return find(dsu[n]);
}
void solve()
{

    int mst = 0, ecnt = 0;
    set<edge> s;
    for (int i = 1; i <= n; i++)
        dsu[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        s.insert(edge(w, x, y));
    }
    for (auto i : s)
    {
        int xr = find(i.x), yr = find(i.y);
        if (xr != yr)
        {
            dsu[xr] = yr;
            mst += i.w;
            ecnt++;
        }
        dsu[i.y] = yr;
        dsu[i.x] = find(i.x);
        if (ecnt == n - 1)
            break;
    }
    int root = find(1);
    for (int i = 1; i <= n; i++)
        if (find(i) != root)
        {
            cout << -1 << '\n';
            return;
        }
    cout << mst << '\n';
}
int main()
{
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            return 0;
        solve();
    }
}