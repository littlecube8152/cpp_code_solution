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

int N, K, B, pre[100005], ans = 1e9;
signed main()
{
    fast;
    ifstream cin("maxcross.in");
    ofstream cout("maxcross.out");

    cin >> N >> K >> B;
    for (int i = 1; i <= B; i++)
    {
        int a;
        cin >> a;
        pre[a] = 1;
    }
    for (int i = 1; i <= N; i++)
        pre[i] += pre[i - 1];
    for (int i = K; i <= N; i++)
        ans = min(ans, pre[i] - pre[i - K]);
    cout << ans << '\n';
}