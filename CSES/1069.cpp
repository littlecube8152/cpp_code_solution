#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string s;
int ans, tmp = 1;
signed main()
{
    fast;
    cin >> s;
    for (int i = 0; i < s.size() - 1;i++)
    {
        if(s[i] == s[i+1])
            tmp++;
        else{
            ans = max(ans, tmp);
            tmp = 1;

        }
    }
    cout << max(tmp, ans);
}