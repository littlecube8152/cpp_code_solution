#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, tot[500005], ans;

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int a, cnt = 1;
        cin >> a;
        for (int i = max(0, a - 2); i <= min(a + 2, N); i++)
            cnt = (cnt + tot[i]) % MOD;
        tot[a] = (tot[a] + cnt) % MOD;
        ans = (ans + cnt) % MOD;
    }
    cout << ans << '\n';
}
