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

int N;
ll arr[100005], pre[100005];

signed main()
{
    fast;
    ifstream cin("sabotage.in");
    ofstream cout("sabotage.out");
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    for (int i = 1; i <= N; i++)
        arr[i] *= 100000;
    ll L = 1, R = 1000000000;
    while (L < R)
    {
        ll mid = (L + R) / 2, cur = 1e18, mx = -1e18;
        for (int i = 1; i < N; i++)
        {
            pre[i] = pre[i - 1] + arr[i] - mid;
            mx = max(mx, pre[i] - cur);
            cur = min(cur, pre[i]);
        }
        for (int i = 1; i <= N; i++)
            mx -= arr[i] - mid;
        if (mx >= 0)
            R = mid;
        else
            L = mid + 1;
    }
    // cerr << L << '\n';
    L += 50;
    cout << L / 100000 << '.';
    if (L % 100000 / 100 < 10)
        cout << "00" << L % 100000 / 100 << '\n';
    else if (L % 100000 / 100 < 100)
        cout << "0" << L % 100000 / 100 << '\n';
    else
        cout << L % 100000 / 100 << '\n';
}