#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v[1005], leaf;
        queue<int> q;
        int deg[1005] = {0}, dp[1005] = {0}, time[1005], n, res = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> time[i];
            int ndeg, x;
            cin >> ndeg;
            while (ndeg--)
            {
                cin >> x;
                v[i].emplace_back(x);
                deg[x]++;
            }
        }
        for (int i = 1; i <= n; i++)
            if (deg[i] == 0)
            {
                q.push(i);
                dp[i] = time[i];
            }
            else if (v[i].empty())
                leaf.emplace_back(i);
        while (!q.empty())
        {
            for (int i : v[q.front()])
            {
                dp[i] = max(dp[i], dp[q.front()] + time[i]);
                deg[i]--;
                if(!deg[i])
                    q.push(i);
            }
            q.pop();
        }
        for(int i : leaf)
            res = max(res, dp[i]);
        cout << res << '\n';
    }
}