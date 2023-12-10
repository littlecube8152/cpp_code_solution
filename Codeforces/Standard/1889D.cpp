#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

int n, last[100005], ans[100005];
vector<int> v[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, k;
        cin >> k;
        while (k--)
        {
            cin >> a;
            v[i].emplace_back(a);
        }
    }
}