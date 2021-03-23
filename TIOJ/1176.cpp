#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, a[1000005], b[1000005], m;
stack<ll> v;

signed main()
{
    fast;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        a[i] = m;
        while (!v.empty())
        {
            if (m >= a[v.top()])
            {
                b[v.top()] = i - v.top();
                v.pop();
            }
            else
                break;
        }
        v.push(i);
    }
    while (!v.empty())
    {
        b[v.top()] = n - v.top() - 1;
        v.pop();
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << '\n';
}