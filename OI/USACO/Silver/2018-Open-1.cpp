#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, ans;
pii a[100005];

signed main()
{
    fast;
     ifstream cin("sort.in");
     ofstream cout("sort.out");
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i].F;
        a[i].S = i;
    }
    stable_sort(a + 1, a + 1 + N);
    for (int i = 1; i <= N; i++)
        ans = max(ans, a[i].S - i + 1);
    cout << ans << '\n';
}