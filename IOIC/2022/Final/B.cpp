#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int C = 1000;

ll c[1005][1005], T, L, R, N;
vector<ll> v[1005];

int main()
{
    for (int i = 0; i <= C; i++)
        c[0][i] = c[i][0] = 1;
    for (int i = 1; i <= C; i++)
        for (int j = 1; j <= C; j++)
        {
            if (c[i - 1][j] > 0 && c[i][j - 1] > 0 && c[i - 1][j] + c[i][j - 1] <= 1e13)
                c[i][j] = c[i - 1][j] + c[i][j - 1];
            else
                c[i][j] = -1;
        }
   
    for (int sum = 0; sum <= C; sum++)
    {
        for (int i = 0; i <= sum; i++)
            v[sum].emplace_back(c[i][sum - i]);
        sort(v[sum].begin(), v[sum].end());
    }
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int ans = 0;
        cin >> L >> R >> N;
        for (int i = 0; i <= N; i++)
            ans += upper_bound(v[i].begin(), v[i].end(), R) - lower_bound(v[i].begin(), v[i].end(), L);
        cout << ans << '\n';
    }
}