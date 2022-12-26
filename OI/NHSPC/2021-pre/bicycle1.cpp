#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll X, Y, N, arr[1000005], v[1000005];
long double ans;
signed main()
{
    cin >> X >> Y >> N;
    for (int i = 0; i <= N; i++)
        cin >> arr[i];
    for (int i = 1; i <= N; i++)
        cin >> v[i];
    for (int i = 1; i <= N; i++)
        ans += (long double)(arr[i] - arr[i - 1]) / (long double)(v[i]);
    cout << fixed << setprecision(10) << ans << '\n';
}