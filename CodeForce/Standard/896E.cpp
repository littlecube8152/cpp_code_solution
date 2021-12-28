#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#pragma pack(0)
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

int n, m, arr[100001], k, l, r, x;

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> k >> l >> r >> x;
        if (k == 1)
        {
            for (int i = l; i <= r; i++)
                if (arr[i] > x)
                    arr[i] -= x;
        }
        else
        {
            int res = 0;
            for (int i = l; i <= r; i++)
                if (arr[i] == x)
                    res++;
            cout << res << '\n';
        }

    }
}