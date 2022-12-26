#include <bits/stdc++.h>
#define ll long long
#define plll tuple<ll, ll, ll>
using namespace std;

int n, l, q, a[10005], ans[10005][105], pos[10005], b[105], qu[105];
signed main()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> b[i];
        qu[i] = b[i];
    }
    sort(qu + 1, qu + 1 + q);
    for (int i = q; i >= 1; i--)
        for (int j = qu[i - 1]; j <= qu[i]; j++)
            pos[j] = i;
    for (int d = 1; d <= n - l; d++)
    {
        int cur = 0;
        for (int i = 0; i < l; i++)
            cur += a[i] != a[i + d];
        for (int i = 1; i + l - 1 + d <= n; i++)
        {
            cur -= a[i - 1] != a[i - 1 + d];
            cur += a[i + l - 1] != a[i + l - 1 + d];
            ans[i][pos[cur]]++;
            ans[i + d][pos[cur]]++;
        }
    }
    for (int i = 1; i <= q; i++)
        for (int j = 1; j <= n - l + 1; j++)
        {
            int sum = 0;
            for (int k = 1; k <= q; k++)
                if (qu[k] <= b[i])
                    sum += ans[j][k];
            cout << sum << " \n"[j == n - l + 1];
        }
}
