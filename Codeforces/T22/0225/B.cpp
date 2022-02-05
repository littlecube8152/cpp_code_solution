#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, c[200005], a[200005], pre[200005], res;
bool tp[200005], vis[200005];
int main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == i)
        {
            tp[i] = 1;
            vis[i] = 1;
        }
    }
    stack<int> s;
    int k = 1;
    while (1)
    {
        if (s.empty())
        {
            for (; k <= n;k++)
                if (!vis[k])
                {
                    s.push(k);
                    break;
                }
            if (s.empty())
                break;
        }

        int top = s.top();
        s.pop();
        vis[top] = 1;

        //cout << "DFS " << top << '\n';
        if (vis[a[top]])
        {
            bool iscycle = true;
            int i = top;
            vector<int> cycleid;
            while (i != a[top])
            {
                if (i <= 0)
                {
                    iscycle = 0;
                    break;
                }
                cycleid.emplace_back(i);
                i = pre[i];
            }
            if (iscycle)
            {
                int minid = i, mincost = c[i];
                for (int j : cycleid)
                {
                    if (c[j] < mincost)
                    {
                        minid = j;
                        mincost = c[j];
                    }
                }
                tp[minid] = 1;
            }
        }
        else
        {
            pre[a[top]] = top;
            s.push(a[top]);
        }
    }

    for (int i = 1; i <= n; i++)
        if (tp[i])
            res += c[i];
    cout << res;
}