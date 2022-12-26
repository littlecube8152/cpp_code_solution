#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, d, x[2005], y[2005], ans = 1;
map<pii, int> mp;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> d;
    assert(d == 0);
    for (int i = 1; i <= N; i++)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= N; i++)
    {
        ll cnt = 0;
        for (int j = 1; j <= N; j++)
            if (x[i] == x[j] && y[i] == y[j])
                cnt++;
            else
            {
                pii p = {x[j] - x[i], y[j] - y[i]};
                if (p.F < 0)
                    p.F *= -1, p.S *= -1;
                int gcd = __gcd(abs(p.F), abs(p.S));
                p.F /= gcd;
                p.S /= gcd;
                mp[p]++;
            }
        for (auto [_, p] : mp)
            ans = max(ans, p + cnt);
        mp.clear();
    }
    cout << ans << '\n';
}