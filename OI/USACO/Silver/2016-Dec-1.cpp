#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
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

int N, Q, arr[100005];
signed main()
{
    fast;
    ifstream cin("haybales.in");
    ofstream cout("haybales.out");

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    sort(arr + 1, arr + 1 + N);
    for (int i = 1; i <= Q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << upper_bound(arr + 1, arr + 1 + N, b) - lower_bound(arr + 1, arr + 1 + N, a) << '\n';
    }
}
//