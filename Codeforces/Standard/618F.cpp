#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

int n;
ll a[1000006], b[1000006];
vector<pii> v[1000006];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    partial_sum(a, a + 1 + n, a);
    partial_sum(b, b + 1 + n, b);
    bool flag = 0;
    if (a[n] > b[n])
        swap(a, b), flag = 1;
    for (int i = 0; i <= n; i++)
    {
        auto iter = lower_bound(b, b + 1 + n, a[i]);
        v[*iter - a[i]].emplace_back(i, iter - b);
    }
    for (int i = 0; i < n; i++)
        if(v[i].size() >= 2)
        {
            pii sola(v[i][0].F, v[i][1].F), solb(v[i][0].S, v[i][1].S);
            if (flag)
                swap(sola, solb);
            cout << sola.S - sola.F << '\n';
            for (int j = sola.F + 1; j <= sola.S; j++)
                cout << j << " \n"[j == sola.S];
            cout << solb.S - solb.F << '\n';
            for (int j = solb.F + 1; j <= solb.S; j++)
                cout << j << " \n"[j == solb.S];
            return 0;
        }
    assert(false);
}