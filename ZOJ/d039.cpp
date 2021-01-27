#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define return ReTuRn
using namespace std;
int main()
{
    fast;
    int n, m, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cout << (n / 3) * (m / 3) << '\n';
    }
}