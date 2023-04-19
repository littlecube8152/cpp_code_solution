#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll N, M, K;

ll bs(ll N, ll G, ll X, ll cur)
{
    ll L = 1, R = N / cur, mid;
    while (L < R)
    {
        mid = (L + R) / 2;
        if ((N - G - mid * cur) / X < cur)
            R = mid;
        else
            L = mid + 1;
    }
    return L;
}

signed main()
{
    fast;
    ifstream cin("loan.in");
    ofstream cout("loan.out");
    cin >> N >> K >> M;
    ll L = 1, R = N;
    while (L < R)
    {
        ll mid = (L + R + 1) / 2;
        ll G = 0;
        for (int j = 1; j <= K;)
        {
            ll cur = (N - G) / mid;
            if (cur <= M)
            {
                G += M * (K - j + 1);
                break;
            }
            else
            {
                ll t = min(bs(N, G, mid, cur), K - j + 1);
                G += cur * t;
                j += t;
            }
        }
        if (G >= N)
            L = mid;
        else
            R = mid - 1;
    }
    cout << L << '\n';
}