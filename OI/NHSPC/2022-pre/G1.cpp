#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int C = 2000000, B = 1420;
int N, M, Q, a[2000006], val[2000006];
vector<pii> v;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        val[a[i]]++;
    }
    for (int i = 1; i <= C; i++)
        if (val[i])
            v.emplace_back(pii(i, val[i]));
    
    for (int t = 1; t <= Q; t++)
    {
        int b;
        cin >> b;
        int ans = 0;
        for (auto [i, d] : v)
        {
            int j = i, k = 0;
            while (j)
            {
                k += j % b;
                j /= b;
            }
            ans += (int)(k == M) * d;
        }
        cout << ans << '\n';
    }
}