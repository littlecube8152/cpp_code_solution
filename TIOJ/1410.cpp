#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<pll> v;

int main()
{
    fast;
    int n, r = 0, maxr = 0;
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        v.emplace_back(make_pair(x, 1));
        v.emplace_back(make_pair(y + 1, -1));
    }
    sort(v.begin(), v.end());
    for(auto i: v)
    {
        r += i.second;
        maxr = max(maxr, r);
    }
    cout << maxr << '\n';
}