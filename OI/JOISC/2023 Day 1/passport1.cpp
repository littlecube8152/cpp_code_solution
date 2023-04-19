#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, Q, L[200005], R[200005];
signed main()
{
    cin >> N;
    int r = 1, nxt = 0, ans = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> L[i] >> R[i];
        if (i > r)
        {
            if (nxt < i)
            {
                cout << -1 << '\n';
                return 0;
            }
            r = nxt, ans++;
        }
        if (i <= r)
            nxt = max(nxt, R[i]);
    }
    cout << ans << '\n';
}