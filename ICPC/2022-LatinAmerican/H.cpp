#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

int n, q, m, k, low[305], in[305], fix[305], cnt[305];
map<string, int> mp;
string s[305];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i], mp[s[i]] = i;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> m >> k;
        cnt[k]++;
        for (int j = 1; j <= m; j++)
        {
            string t;
            cin >> t;
            int l = mp[t];
            if (k > low[l])
                low[l] = k, in[l] = 1;
            else if (k == low[l])
                in[l]++;
        }
    }
    vector<int> sol;
    for (int i = 1; i <= n; i++)
    {
        if (low[i] && !fix[low[i]] && cnt[low[i]] == in[i])
            fix[low[i]] = i;
        else
            sol.emplace_back(i);
    }
    sort(all(sol), [&](int i, int j)
         { return low[i] > low[j]; });
    for (int i = 1; i <= n; i++)
        if (fix[i])
            cout << s[fix[i]] << " \n"[i == n];
        else
        {
            cout << s[sol.back()] << " \n"[i == n];
            sol.pop_back();
        }
}