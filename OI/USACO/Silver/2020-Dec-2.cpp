#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll N, x[2505], y[2505], l[2505], pre[2505][2505], ans;

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= N; i++)
        l[i] = x[i];
    sort(l + 1, l + 1 + N);
    for (int i = 1; i <= N; i++)
        x[i] = lower_bound(l + 1, l + 1 + N, x[i]) - l;
    for (int i = 1; i <= N; i++)
        l[i] = y[i];
    sort(l + 1, l + 1 + N);
    for (int i = 1; i <= N; i++)
        y[i] = lower_bound(l + 1, l + 1 + N, y[i]) - l;
    for (int i = 1; i <= N; i++)
        pre[x[i]][y[i]] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    ans += 1;
    ans += N;
    ans += N * (N - 1) / 2;
    ans += N * (N - 1) * (N - 2) / 6;
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
        {
            int x1 = x[i], x2 = x[j], y1 = y[i], y2 = y[j];
            if (x1 < x2)
                swap(x1, x2);
            if (y1 < y2)
                swap(y1, y2);
            ans -= pre[x1 - 1][y1 - 1] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x2][y2];
        }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (y[i] > y[j])
            {
                int x1 = min(x[i], x[j]), x2 = max(x[i], x[j]);
                ans += (pre[x1 - 1][y[i] - 1] - pre[x1 - 1][y[j]]) *
                       (pre[N][y[i] - 1] - pre[x2][y[i] - 1] - pre[N][y[j]] + pre[x2][y[j]]);
            }
    cout << ans << '\n';
}