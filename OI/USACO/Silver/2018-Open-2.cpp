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

int N, w[100005], ans;
signed main()
{
    fast;
    ifstream cin("lemonade.in");
    ofstream cout("lemonade.out");

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> w[i];
    sort(w + 1, w + 1 + N, greater<>());
    for (int i = 1; i <= N; i++)
        if(w[i] >= ans)
            ans++;
    cout << ans << '\n';
}