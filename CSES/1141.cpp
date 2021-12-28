#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, ans;
map<int, int> mp;
queue<int> q;
signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (mp[x])
            while (!q.empty())
            {
                mp[q.front()]--;
                if (q.front() == x)
                {
                    q.pop();
                    break;
                }
                q.pop();
            }
        mp[x]++;
        q.push(x);
        ans = max(ans, (int)q.size());
    }
    cout << ans << '\n';
}