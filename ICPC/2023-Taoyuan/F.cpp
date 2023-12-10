#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;

ll n, d[1005], s[1005], o[1005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        cin >> d[i] >> s[i];
        for (int i = 1; i <= n; i++)
            o[i] = i;
        sort(o + 1, o + 1 + n, [&](int i, int j) { return pll(d[i] * s[j], i) < pll(d[j] * s[i], j); });

        for (int i = 1; i <= n; i++)
            cout << o[i] << " \n"[i == n];

        if (t != 0)
            cout << '\n';
    }
}