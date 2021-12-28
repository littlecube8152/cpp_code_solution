#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, m, dis[200005];
vector<pll> v[200005];
set<pll> st;
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        v[x].pb(make_pair(y, w));
        v[x].pb(make_pair(y + n, w / 2));
        v[x + n].pb(make_pair(y + n, w));
    }
    for (int i = 2; i <= n; i++)
        dis[i] = 1000000000000000, dis[i + n] = 1000000000000000;
    st.insert(make_pair(0, 1));
    while (!st.empty())
    {
        pll p = *st.begin();
        st.erase(st.begin());
        for (auto i : v[p.S])
        {
            if (dis[p.S] + i.S < dis[i.F])
            {
                auto iter = st.find(make_pair(dis[i.F], i.F));
                if (iter != st.end())
                    st.erase(iter);
                dis[i.F] = dis[p.S] + i.S;
                st.insert(make_pair(dis[i.F], i.F));
            }
        }
    }
    cout << dis[2 * n] << " ";
}