#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, x, val[200005], ans;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> x;
    for (int i = 1; i <= N; i++)
        cin >> val[i];

    vector<int> v;
    for (int i = 1; i <= N; i++)
    {
        int idx = lower_bound(v.begin(), v.end(), val[i]) - v.begin();
        if (idx == v.size())
            v.emplace_back(val[i]);
        else
            v[idx] = val[i];
    }

    cout << v.size() << '\n';
}
