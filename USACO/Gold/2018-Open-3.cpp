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

int n, v, t[255], w[255];

int bs(int l, int r)
{
    if (l == r)
        return l;
    int mid = (l + r + 1) / 2;
    int sum = 0, tw = 0, dp[1005] = {0};
    bool b[255] = {0};
    for (int i = 0; i < n; i++)
        if (t[i] - mid * w[i] >= 0)
        {
            b[i] = 1;
            tw += w[i];
            sum += (t[i] - mid * w[i]);
        }
    if (tw >= v)
        return bs(mid, r);
    dp[tw] = sum;

    for (int i = 0; i < n; i++)
        if (!b[i])
            for (int j = v; j > 0; j--)
            {
                if (j + w[i] >= v && dp[j] + (t[i] - mid * w[i]) >= 0)
                    return bs(mid, r);
                if (j + w[i] < v)
                    dp[j + w[i]] = max(dp[j + w[i]], dp[j] + (t[i] - mid * w[i]));
            }

    //cout << l << " " << r << " " << sum << '\n';
    return bs(l, mid - 1);
}

signed main()
{
    fast;

    ifstream cin;
    cin.open("talent.in");
    ofstream cout;
    cout.open("talent.out");
    cin >> n >> v;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> t[i];
        t[i] *= 1000;
    }
    cout << bs(0, 100000000) << '\n';
}