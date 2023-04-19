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
    int ans = 0;
    char c;
    while(cin >> c)
        ans += (c == '8' ? 2 : ((c == '0' || c == '4' || c == '6' || c == '9') ? 1 : 0));
    cout << ans + 1 << '\n';
}