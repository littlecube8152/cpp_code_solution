#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;
ll a[500005], n, k, d;
map<int, int> dp;

int main()
{
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int front = lower_bound(a + 1, a + 1 + n, a[i] - d) - a - 1, back = i - k;
        if (dp[back] - dp[front - 1] > 0)
            dp[i] = 1;
        dp[i] = dp[i] + dp[i - 1];
    }
    if (dp[n] - dp[n - 1] > 0)
        puts("YES");
    else
        puts("NO");
}