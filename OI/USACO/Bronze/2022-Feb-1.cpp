#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, arr[100005], sum, ans;

void solve()
{
    cin >> N;
    sum = 0, ans = N - 1;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum == 0)
    {
        cout << 0 << '\n';
        return;
    }
    for (int i = 1; i <= sum; i++)
        if (sum % i == 0)
        {
            int cur = 0;
            bool valid = 1;
            for (int j = 1; j <= N; j++)
            {
                cur += arr[j];
                if (cur == i)
                    cur = 0;
                else if (cur > i)
                    valid = 0;
            }
            if (valid)
                ans = min(ans, N - sum / i);
        }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}