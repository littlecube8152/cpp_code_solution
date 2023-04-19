#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, arr[100005][3];
ll ans;

signed main()
{
    cin >> N;
    for (int i = 1; i <= 2 * N; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (x <= 1 && y <= 1)
        {
            arr[1][1]++;
            ans += abs(x - 1) + abs(y - 1);
        }
        else if (x <= 1 && y >= 2)
        {
            arr[1][2]++;
            ans += abs(x - 1) + abs(y - 2);
        }
        else if (x >= N && y <= 1)
        {
            arr[N][1]++;
            ans += abs(x - N) + abs(y - 1);
        }
        else if (x >= N && y >= 2)
        {
            arr[N][2]++;
            ans += abs(x - N) + abs(y - 2);
        }
        else if (y >= 2)
        {
            arr[x][2]++;
            ans += abs(y - 2);
        }
        else if (y <= 1)
        {
            arr[x][1]++;
            ans += abs(y - 1);
        }
    }
    int cur[3] = {};
    for (int i = 1; i <= N; i++)
    {
        cur[1] += arr[i][1];
        cur[2] += arr[i][2];
        while (cur[1] <= 0 && 2 <= cur[2])
            cur[1]++, cur[2]--, ans++;
        while (cur[2] <= 0 && 2 <= cur[1])
            cur[2]++, cur[1]--, ans++;
        cur[1]--;
        cur[2]--;
        ans += abs(cur[1]) + abs(cur[2]);
    }
    cout << ans << '\n';
}