#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string a, b;
int ans;

signed main()
{
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
    {
        int k = 0;
        for (int j = 0; j < b.length(); j++)
            if (i + j >= a.length())
                break;
            else if(a[i + j] == b[j])
                k++;
        ans = max(ans, k);
    }
    swap(a, b);
     for (int i = 0; i < a.length(); i++)
    {
        int k = 0;
        for (int j = 0; j < b.length(); j++)
            if (i + j >= a.length())
                break;
            else if(a[i + j] == b[j])
                k++;
        ans = max(ans, k);
    }
    cout << ans << '\n';
}