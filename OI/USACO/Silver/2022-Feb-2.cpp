#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, x[50], y[50], ans[50];
vector<pll> v[25], u[25];

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
        u[i].swap(v[i]);
        sort(u[i].begin(), u[i].end());
    }
    brute(N / 2 + 1, N, 0, 0, 0);
    for (int i = 0; i <= N / 2 + 1; i++)
    {
        sort(v[i].begin(), v[i].end(), greater<pll>());

        for (int j = 0; j <= N / 2; j++)
        {
            ll ptr = 0, cnt = 0;
            for (int k = 0; k < v[i].size(); k++)
            {
                if (k == 0 || v[i][k] != v[i][k - 1])
                {
                    cnt = 0;
                    while (ptr < u[j].size() && u[j][ptr] <= pll{x[0] - v[i][k].F, y[0] - v[i][k].S})
                    {
                        //cout << "cur " << v[i][k].F << ", " << v[i][k].S << "  ptr++ " << u[j][ptr].F << ", " << u[j][ptr].S << '\n';
                        if (u[j][ptr] == pll{x[0] - v[i][k].F, y[0] - v[i][k].S})
                            cnt++;
                        ptr++;
                    }
                }
                ans[i + j] += cnt;
            }
        }
    }
    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';
}