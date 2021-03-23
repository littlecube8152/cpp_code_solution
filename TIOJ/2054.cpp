#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int plane[3005][3005], x[3005], y[3005], n, l, w, m;
pii plot[3005];
signed main()
{
    cin >> n >> l >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> plot[i].first >> plot[i].second;
        x[i] = plot[i].first;
        y[i] = plot[i].second;
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    for (int i = 1; i <= n; i++)
        plane[(lower_bound(x + 1, x + n + 1, plot[i].first) - x)][(lower_bound(y + 1, y + n + 1, plot[i].second) - y)]++;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            plane[i][j] += plane[i][j - 1];
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= n; i++)
            plane[i][j] += plane[i - 1][j];

    int xlower = 1, xupper = 1;
    while (xlower <= n)
    {
        while (x[xupper + 1] - x[xlower] <= w && xupper + 1 <= n)
            xupper++;
        int ylower = 1, yupper = 1;
        while (ylower <= n)
        {
            while (y[yupper + 1] - y[ylower] <= l && yupper + 1 <= n)
                yupper++;
            m = max(m, plane[xupper][yupper] - plane[xlower - 1][yupper] - plane[xupper][ylower - 1] + plane[xlower - 1][ylower - 1]);
            //cout << "One of the possible maxmium is: " << plane[xupper][yupper] - plane[xlower - 1][yupper] - plane[xupper][ylower - 1] + plane[xlower - 1][ylower - 1] << '\n';
            ylower++;
        }
        xlower++;
    }
    cout << m << '\n';
}