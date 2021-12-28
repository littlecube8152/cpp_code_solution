#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, k, dp[5005], ks[5005];
pii w[5005];
ll res = 1;
unordered_map<char, int> ump;
ll fpow(ll b, ll p)
{
    ll ans = 1, m = b;
    while (p)
    {
        if (p & 1)
            ans = ans * m % MOD;
        m = m * m % MOD;
        p >>= 1;
    }
    return ans;
}

signed main()
{
    fast;
    ifstream cin("poetry.in");
    ofstream cout("poetry.out");
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> w[i].F >> w[i].S;
    for (int i = 1; i <= m; i++)
    {
        char c;
        cin >> c;
        ump[c]++;
    }
    ks[0] = 1;
    for (int i = 0; i < k; i++)
        for (int j = 1; j <= n; j++)
            if (i + w[j].F < k)
                ks[i + w[j].F] = (ks[i + w[j].F] + ks[i]) % MOD;
            else if (i + w[j].F == k)
                dp[w[j].S] = (dp[w[j].S] + ks[i]) % MOD;
    for (auto i : ump)
    {
        ll tmp = 0;
        for (int j = 1; j <= n; j++)
            if (dp[j] != 0)
                tmp = tmp + fpow(dp[j], i.S) % MOD;
        
        res = res * tmp % MOD;
    }
    cout << res << '\n';
}