//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, k;
bool dp[100005];
vector<int> v;

signed main()
{
    cin >> k >> n;
    v.resize(k);
    for (int i = 0; i < k; i++)
        cin >> v[i];
    for (int i = 0; i <= n; i++)
        for (int j : v)
            if (i + j <= n)
                dp[i + j] |= !dp[i];
    if (dp[n])
        cout << "First\n";
    else
        cout << "Second\n";
}