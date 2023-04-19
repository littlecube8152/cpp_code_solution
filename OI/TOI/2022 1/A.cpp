#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int C = 10'000'000;
ll N, gcd[C + 5], ans;
int arr[100005], d[C + 5];

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    for (int i = 1; i <= N; i++)
        d[arr[i]]++;
    for (int i = 1; i <= C; i++)
        for (int j = i * 2; j <= C; j += i)
            d[i] += d[j];
    for (int i = 1; i <= C; i++)
        gcd[i] = (ll)d[i] * (d[i] - 1);
    for (int i = C; i >= 1; i--)
        for (int j = i * 2; j <= C; j += i)
            gcd[i] -= gcd[j];
    for (int i = 1; i <= C; i++)
        ans += gcd[i] * d[i];
    ans -= N * (N - 1) * 2;
    cout << ans << '\n';
}
