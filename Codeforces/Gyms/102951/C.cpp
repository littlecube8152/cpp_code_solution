#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, val[100005];
vector<int> dp, top;
signed main()
{
    cin >> n;
    top.resize(n);
    for (int i = 0; i < n; i++)
        cin >> top[i];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        val[x] = i;
    }
    for (int i = 0; i < n; i++)
        top[i] = val[top[i]];
    for (int i : top)
    {
        int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
        if(pos == dp.size()) dp.emplace_back(i);
        else
            dp[pos] = i;
    }
    cout << dp.size() << '\n';
}