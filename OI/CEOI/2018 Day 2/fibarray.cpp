#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

ll dp[15001] = {0}, fib[100000] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946};

signed main()
{
    int N;
    cin >> N;
    for (int j = 3; j <= N; j++)
    {
        fib[j] = fib[j - 1] + fib[j - 2];
        cout << fib[j] << '\n';
    }
}
