#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, K, R, arr[200005], acc[200005], lim[200005], remain, ans = 1e9;

signed main()
{
    cin >> N >> K >> R;
    remain = R;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    for (int i = 1; i <= R; i++)
    {
        int B, Q;
        cin >> B >> Q;
        lim[B] = Q;
    }
    for (int l = 1, r = 1; l <= N; l++)
    {
        while(r <= N && remain > 0)
        {
            acc[arr[r]]++;
            if(acc[arr[r]] == lim[arr[r]])
                remain--;
            r++;
        }
        if(remain == 0)
            ans = min(ans, r - l);
        if(acc[arr[l]] == lim[arr[l]])
            remain++;
        acc[arr[l]]--;
    }
    if(ans > N)
        cout << "impossible\n";
    else
        cout << ans << '\n';
}