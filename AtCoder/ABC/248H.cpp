/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll INF = 9223372036854775807;
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll N, K, a[200005], ans, lx[200005], rx[200005], li[200005], ri[200005], exist[400005];

void dc(int L, int R)
{
    if (L == R)
        return;
    int m;
    for (int t = 1; t <= 2; t++)
    {
        for (int i = 0; i <= (R - L) / 2; i++)
            swap(a[L + i], a[R - i]);
        m = (L + R - (t & 1)) / 2;

        lx[m + 1] = rx[m] = 0;
        li[m + 1] = ri[m] = N + 1;
        for (int i = m; i >= L; i--)
            lx[i] = max(lx[i + 1], a[i]), li[i] = min(li[i + 1], a[i]);
        for (int i = m + 1; i <= R; i++)
            rx[i] = max(rx[i - 1], a[i]), ri[i] = min(ri[i - 1], a[i]);
        for (int i = L; i <= m; i++)
        {
            int r = i + lx[i] - li[i];
            for (int j = 0; j <= K; j++)
                if (m < r - j && r - j <= R && rx[r - j] < lx[i] && ri[r - j] > li[i])
                    ans++;
        }
        int rl = m + 1, rr = rl;
        for (int l = m; l >= L; l--)
        {
            while (rr <= R && ri[rr] > li[l])
            {
                exist[rx[rr] - rr + 200000]++;
                rr++;
            }
            while (rl < rr && rx[rl] < lx[l])
            {
                exist[rx[rl] - rl + 200000]--;
                rl++;
            }
            for (int j = 0; j <= K; j++)
                ans += exist[li[l] - l + j + 200000];
        }
        for (; rl < rr; rl++)
            exist[rx[rl] - rl + 200000]--;
    }
    dc(L, m);
    dc(m + 1, R);
}

signed main()
{
    fast;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    dc(1, N);
    cout << ans + N << '\n';
}
