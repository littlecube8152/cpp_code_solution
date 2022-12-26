#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
using namespace std;

ll n, m, t[300005], w[300005], ans;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> w[i] >> t[i] >> w[i];
    for (int i = 1; i <= n; i++)
        t[i] += t[i - 1], w[i] += w[i - 1];
    set<pll> st;
    st.insert({1e17, 0});
    st.insert({t[n], w[n]});
    for (int i = n; i >= 1; i--)
    {
        st.insert({t[i - 1], w[i - 1]});
        auto iter = prev(st.upper_bound({t[i - 1] + m, 0}));
        ans = max(ans, iter->S - w[i - 1]);
    }
    cout << ans << '\n';
}