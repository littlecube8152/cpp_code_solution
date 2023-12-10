#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

ll N, P, H;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> P >> H;
    vector<int> v;
    for (ll i = N; i >= 1; i--)
    {
        ll h = 1LL << (i - 1);
        if (H > h)
            H = 2 * h + 1 - H, v.emplace_back(1);
        else
            v.emplace_back(0);
    }
    for (ll i = N; i >= 1; i--)
    {
        ll h = 1LL << (i - 1);
        if (v[i - 1] == 1)
        {
            if (P <= h)
                cout << 'L', P = h + 1 - P;
            else
                cout << 'R', P = 2 * h + 1 - P;
        }
        else
        {
            if (P <= h)
                cout << 'R';
            else
                cout << 'L', P -= h;
        }
    }
    cout << '\n';
}