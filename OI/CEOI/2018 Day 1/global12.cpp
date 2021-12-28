#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, x, val[100], ans;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> x;
    for (int i = 1; i <= N; i++)
        cin >> val[i];

    for (int l = 1; l <= N; l++)
        for (int r = l; r <= N; r++)
            for (int d = -x; d <= x; d++)
            {
                vector<int> v;
                for (int i = 1; i <= N; i++)
                {
                    int idx;
                    if (l <= i && i <= r)
                        val[i] += d;
                    idx = lower_bound(v.begin(), v.end(), val[i]) - v.begin();
                    if (idx == v.size())
                        v.emplace_back(val[i]);
                    else
                        v[idx] = val[i];
                    if (l <= i && i <= r)
                        val[i] -= d;
                }
                ans = max(ans, (ll)v.size());
            }
    cout << ans << '\n';
}
