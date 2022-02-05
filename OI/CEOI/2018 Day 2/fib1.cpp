#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int dp[15001] = {0}, fib[21] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946};

signed main()
{
    int N;
    cin >> N;
    dp[0] = 1;
    for (int j = 1; j <= 20; j++)
        for (int i = 15000; i >= fib[j]; i--)
            dp[i] += dp[i - fib[j]];
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        sum += fib[x];
        cout << dp[sum] << '\n';
    }
}
