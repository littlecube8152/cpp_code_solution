#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0), \
             cin.tie(0), cout.tie(0)
using namespace std;

ll T;

ll calc(ll N, ll A, ll B)
{
    return (B * N + (A - 1) - 1) / (B - A) * A + (A - 1);
}

signed main()
{
    fast;
    cin >> T;
    while (T--)
    {
        ll N, A, B;
        cin >> N >> A >> B;
        if (B % A != 0)
        {
            ll len = calc(N, A, B);
            cout << len << '\n';
        }
    }
}