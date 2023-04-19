#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll n, h, v[500005], s[500005], sum, ans;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    h = n / 2;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        sum += v[i];
    for (int i = 0; i < h; i++)
        s[0] += v[i];
    for (int i = 1; i < n; i++)
        s[i] = s[i - 1] - v[i - 1] + v[(i + h - 1) % n];
    deque<pll> dq;
    for (int i = 1; i < n - h + 1; i++)
    {
        while (!dq.empty() && dq.back().F < s[i])
            dq.pop_back();
        dq.push_back(pll(s[i], i));
    }
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, sum - dq.front().F);
        if (dq.front().S == i + 1)
            dq.pop_front();
        int j = (i - h + 1 + n) % n;
        while (!dq.empty() && dq.back().F < s[j])
            dq.pop_back();
        dq.push_back(pll(s[j], j));
    }
    cout << ans << '\n';
}