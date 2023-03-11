#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 998244353;
ll N, M, Mfac = 1, ans, b[1000006], pos[1000006];
pll l[1000006], r[1000006];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> b[i];
        pos[b[i]] = i;
        if (b[i] == 0)
            M++, l[i] = r[i] = pll(1, i);
    }
    for (int i = 1; i <= N; i++)
        l[i] = pll(l[i].F + l[i - 1].F, (l[i].S + l[i - 1].S) % mod);
    for (int i = N; i >= 1; i--)
        r[i] = pll(r[i].F + r[i + 1].F, (r[i].S + r[i + 1].S) % mod);
    for (int i = 1; i < M; i++)
        Mfac = Mfac * i % mod;
    M = max(M, 1LL);
    for (int i = 1; i < N; i++)
    {
        if (pos[i] == 0 && pos[i + 1] == 0)
            ans = (ans + Mfac * M % mod * N % mod * 499122177) % mod;
        else if (pos[i + 1] == 0)
        {
            int p = pos[i];
            ans = (ans + (r[p + 1].S - p * r[p + 1].F + (N - p) * l[p - 1].F + l[p - 1].S) % mod * Mfac) % mod;
        }
        else if (pos[i] == 0)
        {
            int p = pos[i + 1];
            ans = (ans + (l[p - 1].F * p - l[p - 1].S + (N + p) * r[p + 1].F - r[p + 1].S) % mod * Mfac) % mod;
        }
        else
            ans = (ans + (pos[i + 1] > pos[i] ? (pos[i + 1] - pos[i]) : (N + pos[i + 1] - pos[i])) * M % mod * Mfac) % mod;
        // cout << ans << '\n';
    }
    cout << (ans + Mfac * M + mod) % mod << '\n';
    /* 
    (1 + 3 + 4) / 3 * M! = 16
    N / 2 * M! = 15
    (1 + 3 + 4) / 3 * M! = 16
    (1 + 2 + 4) / 3 * M! = 14
    */
}