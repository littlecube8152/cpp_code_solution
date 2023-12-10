#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

int n;
ll a[200005], c;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        for (int i = 2; i <= n; i++)
            pq.push(pll(i * c - a[i], i));
        ll cur = a[1];
        while (!pq.empty())
        {
            auto [w, i] = pq.top();
            if (cur >= w)
            {
                cur += a[i];
                pq.pop();
            }
            else
                break;
        }
        cout << (pq.empty() ? "Yes" : "No") << '\n';
    }
}