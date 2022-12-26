#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, arr[205], ans;

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + 1 + n);
    for(int i = 1; i <= n; i++)
        ans += arr[i] * (n - i + 1);
    cout << ans << '\n';
}
