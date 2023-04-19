#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, m, in[1000005], nxt = 0;
vector<int> ans;
vector<int> E[1000005];

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        E[x].emplace_back(y);
        in[y]++;
    }

    for (int i = 1; i <= n; i++)
        if (in[i] == 0 && nxt == 0)
            nxt = i;
        else if (in[i] == 0)
        {
            cout << -1 << '\n';
            return 0;
        }
    ans.emplace_back(nxt);
    while (ans.size() < n)
    {
        for (int i : E[ans.back()])
        {
            in[i]--;
            if (in[i] == 0 && nxt == ans.back())
                nxt = i;
            else if (in[i] == 0)
            {
                cout << -1 << '\n';
                return 0;
            }
        }
        if(nxt == ans.back())
        {
            cout << -1 << '\n';
            return 0;
        }
        ans.emplace_back(nxt);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
}