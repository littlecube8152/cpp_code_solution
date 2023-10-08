#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    vector<pii> v;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        v.emplace_back(pii(i - a + 1, a));
    }
    sort(v.begin(), v.end());
    vector<int> l;
    for (auto [_, y] : v)
    {
        auto iter = upper_bound(l.begin(), l.end(), y);
        if(iter == l.end())
            l.emplace_back(y);
        else
            *iter = y;
    }
    cout << l.size() << '\n';
}