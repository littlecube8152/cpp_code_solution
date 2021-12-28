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
    fast;
    int n, k, r = 0, i;
    cin >> n >> k;
    r = (n + 2 * k) % (2 * k + 1);
    cout << (n + 2 * k) / (2 * k + 1) << '\n';
    if (r > k)
        i = k + 1;
    else
        i = r + 1;
    for (; i <= n; i += (2 * k + 1))
        cout << i << " ";
}