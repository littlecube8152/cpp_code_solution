#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, dis[100005], pre[100005];
vector<int> e[100005];
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        dis[i] = 1000000000;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    queue<int> q;
    dis[1] = 1;
    pre[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        for (int i : e[q.front()])
            if (!pre[i])
            {
                dis[i] = dis[q.front()] + 1;
                pre[i] = q.front();
                q.push(i); 
            }
        q.pop();
    }
    if (dis[n] > n)
        cout << "IMPOSSIBLE";
    else
    {
        cout << dis[n] << '\n';
        stack<int> st;
        st.push(n);
        while (st.top() != 1)
            st.push(pre[st.top()]);
        while (!st.empty())
        {
            cout << st.top() << ' ';
            st.pop();
        }
    }
}