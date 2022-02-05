#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll M, N, dp[2005][2005], c;
vector<pll> vn, vm;

signed int main()
{
    cin >> N;
    vn.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> c >> vn[i].F >> vn[i].S;

    cin >> M;
    vm.resize(M + 1);
    for (int i = 1; i <= M; i++)
        cin >> c >> vm[i].F >> vm[i].S;

    sort(vn.begin() + 1, vn.end());
    sort(vm.begin() + 1, vm.end());

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            if (vn[i].F >= vm[j].F)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + vm[j].S - vn[i].S);
            dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
        }
    cout << dp[N][M] << '\n';
}
