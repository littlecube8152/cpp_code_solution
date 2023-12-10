#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll t, n, k, l[105], r[105], u[105], d[105], fin[105], in[105];
vector<int> E[105], R[105];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i] >> d[i] >> r[i] >> u[i];
            in[i] = 0;
            E[i].clear();
            R[i].clear();
        }
        ll owo = *min_element(l + 1, l + 1 + n);
        for (int i = 1; i <= n; i++)
            fin[i] = owo;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (u[j] <= d[i] || u[i] <= d[j])
                    continue;
                else if (r[i] <= l[j])
                    E[i].emplace_back(j), 
                    R[j].emplace_back(i), in[j]++;
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (in[i] == 0)
                q.emplace(i);
        while(!q.empty())
        {
            auto i = q.front();
            q.pop();
            for (int j : R[i])
                fin[i] = max(fin[i], fin[j] + k);
            fin[i] += r[i] - l[i];
            for (int j : E[i])
                if (--in[j] == 0)
                    q.emplace(j);
        }
        ll ans = (*max_element(u + 1, u + 1 + n) - *min_element(d + 1, d + 1 + n)) * (*max_element(r + 1, r + 1 + n) - *max_element(fin + 1, fin + 1 + n));
        cout << max(0LL, ans) << '\n';
    }
}