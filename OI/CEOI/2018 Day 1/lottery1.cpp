#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, l, Q, val[355], ans[355][355];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> l;
    for (int i = 1; i <= N; i++)
        cin >> val[i];
    for (int i = 1; i <= N - l + 1; i++)
        for (int j = i + 1; j <= N - l + 1; j++)
        {
            map<int, int> mp;
            int k = l;
            for (int x = 0; x < l; x++)
                if(val[x + i] == val[x + j])
                    k--;
            ans[i][k]++;
            ans[j][k]++;
            //cout << i << " " << j << " " << k << '\n';
        }
    for (int i = 1; i <= N - l + 1; i++)
        for (int j = 1; j <= l; j++)
            ans[i][j] += ans[i][j - 1];
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= N - l + 1; j++)
            cout << ans[j][k] << " \n"[j == N - l + 1];
    }
}
