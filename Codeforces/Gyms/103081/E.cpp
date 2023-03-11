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
    int N, ans = 1e9;
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        ans = min(ans, b / a);
    }
    cout << ans << '\n';
}


