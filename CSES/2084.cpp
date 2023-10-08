#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int n;
ll dp[200005], f[200005], s[200005];

bool check(pll l1, pll l2, pll l3)
{
    // (l2.b - l1.b) / (l1.a - l2.a) >= * (l3.b - l2.b) / (l2.a - l3.a)
    return (l2.second - l1.second) * (l2.first - l3.first) >= (l3.second - l2.second) * (l1.first - l2.first);
}

void solve()
{
    deque<pll> dq;
    dq.emplace_back(pll(f[0], dp[0]));
    for (int i = 1; i <= n; i++)
    {
        while ((int)dq.size() >= 2 && s[i] * dq[0].first + dq[0].second < s[i] * dq[1].first + dq[1].second)
            dq.pop_front();
        dp[i] = s[i] * dq[0].first + dq[0].second;
        pll l = pll(f[i], dp[i]);
        while ((int)dq.size() >= 2 && check(dq[(int)dq.size() - 2], dq.back(), l))
            dq.pop_back();
        dq.push_back(l);
    }
}

#define fast ios::sync_with_stdio(0), cin.tie(0)
signed main()
{
    fast;
    cin >> n >> f[0];
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        cin >> f[i];
    for (int i = 0; i <= n; i++)
        f[i] = -f[i];
    solve();
    cout << -dp[n] << '\n';
}
