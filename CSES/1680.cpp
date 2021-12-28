#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, x, y, pre[100005], val[100005];
bool vis[100005];
vector<int> v, e[100005];

void dfs(int n)
{
    for (int i : e[n])
        if (!vis[i])
            vis[i] = 1, dfs(i);
    v.pb(n);
}

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        e[x].pb(y);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            vis[i] = 1, dfs(i);
    reverse(v.begin(), v.end());
    val[1] = 1;
    for (int i : v)
    {
        if (val[i] > 0)
            for (int j : e[i])
                if (val[i] + 1 > val[j])
                    val[j] = val[i] + 1, pre[j] = i;
    }
    if (val[n] == 0)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << val[n] << '\n';
    stack<int> st;
    st.push(n);
    while (st.top() != 1)
        st.push(pre[st.top()]);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}