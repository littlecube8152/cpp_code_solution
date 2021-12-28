#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int dp[1005], dp2[1005], n, a[30], arr[1005], b;
string s;

int main()
{
    cin >> n >> s;
    for (int i = 1; i <= 26; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        arr[i + 1] = s[i] - 'a' + 1;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp2[i] = 10000;
        int tmp[30] = {0};
        for (int j = i; j > 0; j--)
        {
            tmp[arr[j]]++;
            bool exit = 0;
            for (int k = 1; k <= 26; k++)
                if (tmp[k] && i - j + 1 > a[k])
                    exit = 1;
            if (exit)
                break;
            dp[i] = (dp[i] + dp[j - 1]) % MOD;
            dp2[i] = min(dp2[j - 1] + 1, dp2[i]);
            b = max(b, i - j + 1);
        }
    }
    cout << dp[n] << '\n'
         << b << '\n'
         << dp2[n] << '\n';
}