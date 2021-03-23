#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, r, f, dis[4005][4005], ans = 1;
char mp[4005][4005];
signed main()
{
    auto add = [](pii p1, pii p2) { return make_pair(p1.F + p2.F, p1.S + p2.S); };
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];

    if (mp[1][1] == '.')
    {
        cout << 1;
        return 0;
    }

    deque<pii> dq;
    dq.push_front(pii{1, 1});
    dis[1][1] = 1;
    while (!dq.empty())
    {
        pii x = dq.front();
        dq.pop_front();
        for (pii i : vector<pii>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
        {
            pii cur = add(i, x);
            if ((mp[cur.F][cur.S] != 'R' && mp[cur.F][cur.S] != 'F') || dis[cur.F][cur.S] != 0)
                continue;
            if (mp[cur.F][cur.S] == mp[x.F][x.S])
            {
                dq.push_front(cur);
                dis[cur.F][cur.S] = dis[x.F][x.S];
            }
            else if (mp[cur.F][cur.S] != mp[x.F][x.S])
            {
                dq.push_back(cur);
                dis[cur.F][cur.S] = dis[x.F][x.S] + 1;
                ans = max(ans, dis[cur.F][cur.S]);
            }
        }
    }
    cout << ans;
}