#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

int n, m, k, dp[200005][11];
vector<pii> v[200005];
array<int, 11> no = {}, dne;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int &i : dne)
        i = -1e9;
    
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> m >> k;
        for (int i = 1; i <= n + 1; i++)
            v[i].clear();
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= k; j++)
                dp[i][j] = -1e9;

        // all state must be some actual dp set.

        for (int i = 1; i <= m; i++)
        {
            int l, r;
            cin >> l >> r;
            v[l].emplace_back(pii(l, i));
            v[r + 1].emplace_back(pii(l, -i));
        }

        map<pii, array<int, 11>, greater<pii>> mp;
        mp[pii(0, 0)] = no;
        for (int i = 1; i <= n; i++)
        {

            for (auto j : v[i])
                if (j.S < 0)
                {
                    j.S = -j.S;
                    auto iter = mp.find(j);
                    auto pre = next(iter);
                    for (int j = 0; j <= k; j++)
                        pre->S[j] = max(iter->S[j], pre->S[j]);
                    mp.erase(iter);
                }
                else
                    mp[j] = dne;
            // if (mp.rbegin()->F.F == i)

            auto iter = mp.begin();
            for (int j = 0; j <= k; j++)
            {
                if (iter == mp.end())
                    break;
                for (int x = 0; x + j <= k; x++)
                    dp[i][x + j] = max(dp[i][x + j], iter->S[x] + 1);
                ++iter;
            }
            for (int j = 0; j <= k; j++)
                mp.begin()->S[j] = max(mp.begin()->S[j], dp[i][j]);
            // for (int j = 0; j <= k; j++)
            //     cerr << dp[i][j] << " \n"[j == k];
        }

        int ans = 0;

        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= k; j++)
                ans = max(ans, dp[i][j]);
        cout << ans << '\n';
    }
}