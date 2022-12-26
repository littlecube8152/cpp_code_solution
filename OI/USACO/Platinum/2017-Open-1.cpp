#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, K, arr[1005][1005], pre[1005][1005], no[1000005], edge[1000005][4], ans, sum;

signed main()
{
    fast;
    ifstream cin("art.in");
    ofstream cout("art.out");

    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> arr[i][j];
    for (int i = 1; i <= N * N; i++)
        edge[i][1] = edge[i][2] = N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            edge[arr[i][j]][0] = max(edge[arr[i][j]][0], i);
            edge[arr[i][j]][1] = min(edge[arr[i][j]][1], i);
            edge[arr[i][j]][2] = min(edge[arr[i][j]][2], j);
            edge[arr[i][j]][3] = max(edge[arr[i][j]][3], j);
        }
    for (int i = 1; i <= N * N; i++)
        if (edge[i][0] >= edge[i][1])
        {
            no[i] = -1;
            sum++;
            pre[edge[i][0] + 1][edge[i][3] + 1]++;
            pre[edge[i][1]][edge[i][3] + 1]--;
            pre[edge[i][0] + 1][edge[i][2]]--;
            pre[edge[i][1]][edge[i][2]]++;
        }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (pre[i][j] + no[arr[i][j]] > 0)
                no[arr[i][j]] = 1;
    for (int i = 1; i <= N * N; i++)
        if (no[i] <= 0)
            ans++;
    if (sum == 1)
        cout << N * N - 1 << '\n';
    else
        cout << ans << '\n';
}