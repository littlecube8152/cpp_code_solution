#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, ans;

char c[200005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> c[i];
    vector<int> v;
    for (int i = 1; i <= N; i++)
    {
        if (c[i] == '(')
            v.emplace_back(i);
        else if (!v.empty())
        {
            ans += 2 * (N - i + 1) * v.back();
            v.pop_back();
        }
    }

    cout << ans << '\n';
}