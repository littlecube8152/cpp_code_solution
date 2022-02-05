// subtask 1

#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;

int T, n;

int main()
{
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans += i * n / __gcd(i, n);
        cout << ans << '\n';
    }

}
