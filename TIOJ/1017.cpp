#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int t, n;

void solve()
{

    int left, right, res = 0;
    vector<int> v;
    vector<bool> L;
    v.resize(n), L.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    left = v[0];
    for (int i = 1; i < n - 1; i++)
    {
        if (v[i] > left)
            L[i] = 1;
        left = max(left, v[i]);
    }
    right = v[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        if (v[i] < right && L[i])
            res++;
        right = min(right, v[i]);
    }
    cout << res << '\n';
}
int main()
{
    fast;
    cin >> t;
    while (t--)
    {
        cin >> n;
        solve();
    }
}