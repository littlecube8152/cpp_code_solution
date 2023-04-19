#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, x[50], y[50], ans[100];
map<pll, ll> mp[50];
vector<pll> v[50];

void brute(int cur, int end, ll X, ll Y, int cnt)
{
    if (cur <= end)
    {
        brute(cur + 1, end, X, Y, cnt);
        brute(cur + 1, end, X + x[cur], Y + y[cur], cnt + 1);
    }
    else
        v[cnt].emplace_back(pll{X, Y});
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i <= N; i++)
        cin >> x[i] >> y[i];
    brute(1, N / 2, 0, 0, 0);
    for (int i = 0; i <= N / 2; i++)
    {
        for (pll p : v[i])
            mp[i][p]++;
        v[i].clear();
    }
    brute(N / 2 + 1, N, 0, 0, 0);
    for (int i = 0; i <= N / 2 + 1; i++)
    {
        for (auto [X, Y] : v[i])
            for (int j = 0; j <= N / 2; j++)
                ans[i + j] += mp[j][{x[0] - X, y[0] - Y}];
        v[i].clear();
    }
    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';
}