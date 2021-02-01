#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
int main()
{
    int w, l, dp[100005] = {0}, a[100000];
    cin >> w >> l;
    for (int i = 1; i < w; i++)
        cin >> a[i];
    a[0] = 10000000;
    a[w] = 10000000;
    for (int i = 0; i <= w; i++)
    {
        for (int j = i - l; j < i; j++)
        {
            if (j < 0)
                continue;
            dp[i] += a[j];
        }
        dp[i] = min(a[i], dp[i]);
    }
    cout << dp[w];
}