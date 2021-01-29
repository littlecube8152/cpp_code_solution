#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<ll> v;
ll n, k;

ll bs(ll l, ll r)
{
    if (l == r)
        return l;

    ll mid = (l + r) / 2, range = -1;
    for (int i = 0; i < k; i++)
    {
        range = *upper_bound(v.begin(), v.end(), range) + mid;
        if (range >= v.back())
            break;
    }
    if (range >= v.back())
        return bs(l, mid);
    else
        return bs(mid + 1, r);
}

int main()
{
    cin >> n >> k;
    while (n--)
    {
        int m;
        cin >> m;
        v.emplace_back(m);
    }
    sort(v.begin(), v.end());

    cout << bs(1, (v.back() - v.front() + 2 * k - 1) / k) << '\n';
}