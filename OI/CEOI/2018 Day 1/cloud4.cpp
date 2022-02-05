#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll M, N, com[100005], order[100005], f;
vector<pll> vn, vm;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    vn.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> vn[i].F >> f >> vn[i].S;

    cin >> M;
    vm.resize(M + 1);
    for (int i = 1; i <= M; i++)
        cin >> vm[i].F >> f >> vm[i].S;

    for (int i = 1; i <= 100000; i++)
        com[i] = 1e18;

    for (int i = 1; i <= N; i++)
        for (int j = i * 50; j >= vn[i].F; j--)
            com[j] = min(com[j], com[j - vn[i].F] + vn[i].S);

    for (int i = 1; i <= M; i++)
        for (int j = i * 50; j >= vm[i].F; j--)
            order[j] = max(order[j], order[j - vm[i].F] + vm[i].S);

    for (int i = N * 50 - 1; i >= 0; i--)
    {
        com[i] = min(com[i], com[i + 1]);
        //cout << com[i] << '\n';
    }

    ll ans = 0;

    for (int i = 0; i <= M * 50; i++)
        ans = max(ans, order[i] - com[i]);

    cout << ans << '\n';
}
