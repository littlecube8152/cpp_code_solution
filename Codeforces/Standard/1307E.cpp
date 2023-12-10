#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

const ll mod = 1'000'000'007;
pll operator+(pll p, pll q)
{
    return pll(p.F + q.F, p.S * q.S % mod);
}
pll chmax(pll p, pll q)
{
    pll r(max(p.F, q.F), 0);
    r.S = (r.F == p.F ? p.S : 0LL) + (r.F == q.F ? q.S : 0LL);
    r.S %= mod;
    return r;
}

int n, m, s[5005], h[5005], l[5005], r[5005];
vector<int> v[5005], f[5005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        v[s[i]].emplace_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int a;
        cin >> a >> h[i];
        if (v[a].size() >= h[i])
        {
            f[a].emplace_back(i);
            l[i] = v[a][h[i] - 1];
            r[i] = v[a][v[a].size() - h[i]];
        }
    }
    pll cur(0, 1);
    for (int i = 0; i <= n; i++)
    {
        // left = i, right = i + 1, at least one of them is exact left
        pll dp[2] = {{0, 1}, {-1e9, 1}};

        for (int j = 1; j <= n; j++)
            if (f[j].size())
            {
                ll a[8] = {1}, b[8] = {1};
                for (int k : f[j])
                {
                    for (int t = 0; t < 8; t++)
                        b[t] = a[t];

                    if (l[k] < i) // add 1
                        for (int t : {0, 2})
                            b[t + 1] = (b[t + 1] + a[t]) % mod;

                    else if (l[k] == i) // add 5
                        for (int t : {0, 2})
                            b[t + 5] = (b[t + 5] + a[t]) % mod;

                    if (r[k] > i) // add 2
                        for (int t : {0, 1, 5})
                            b[t + 2] = (b[t + 2] + a[t]) % mod;

                    swap(a, b);
                }
                pll tmp[2] = {};
                for (int t = 0; t < 8; t++)
                    if (a[t])
                        tmp[t >= 4 || i == 0] = chmax(tmp[t >= 4 || i == 0], pll(__builtin_popcount(t & 3), a[t]));
                dp[1] = chmax(dp[1] + chmax(tmp[0], tmp[1]), dp[0] + tmp[1]);
                dp[0] = dp[0] + tmp[0];
            }
        cur = chmax(cur, dp[1]);
    }
    cout << cur.F << ' ' << cur.S << '\n';
}