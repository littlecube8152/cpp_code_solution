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

int arr[105], n, c, t;

void solve(int i)
{

    cin >> n >> c;
    c -= (n - 1);
    for (int j = 1; j <= n; j++)
        arr[j] = j;
    for (int j = n - 1; j >= 1; j--)
    {
        if (c > 0)
        {
            int revlen = min(c, n - j);
            for (int k = j; k < j + (revlen + 1) / 2; k++)
                swap(arr[k], arr[j + revlen - (k - j)]);
            c -= revlen;
        }
        if (c < 0)
        {
            cout << "Case #" << i << ": IMPOSSIBLE\n";
            return;
        }

    }
    if (c > 0)
    {
        cout << "Case #" << i << ": IMPOSSIBLE\n";
        return;
    }
    cout << "Case #" << i << ": ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << '\n';
}

signed main()
{
    fast;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
}