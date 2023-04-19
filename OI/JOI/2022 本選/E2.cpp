#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int H, W, arr[1503][1503];
ll ans;

signed main()
{
    cin >> H >> W;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            cin >> arr[i][j];
    for (int h1 = 1; h1 <= H; h1++)
        for (int h2 = h1; h2 <= H; h2++)
            for (int w1 = 1; w1 <= W; w1++)
                for (int w2 = w1; w2 <= W; w2++)
                {
                    vector<pii> v;
                    for (int i = h1; i <= h2; i++)
                        for (int j = w1; j <= w2; j++)
                            v.emplace_back(pii{i, j});
                    sort(v.begin(), v.end(), [&](pii p1, pii p2)
                         { return arr[p1.F][p1.S] < arr[p2.F][p2.S]; });
                    bool valid = 1;
                    for (int i = 1; i < v.size(); i++)
                        valid &= (abs(v[i].F - v[i - 1].F) + abs(v[i].S - v[i - 1].S) == 1);
                    if (valid)
                        ++ans;
                }
    cout << ans << '\n';
}