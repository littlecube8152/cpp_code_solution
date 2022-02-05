#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long

long long N, L, K, A, ansi;
long long avr = 0, ans = 1000000000000000000;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> L >> K >> N;
    avr = (L - 1) / K + 1;
    for (int i = 1; i <= N; i++)
    {
        cin >> A;
        if (abs(K * A - avr) < ans)
            ansi = i, ans = abs(K * A - avr);
    }
    cout << ansi << '\n';
}