/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#include <bits/extc++.h>
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
using namespace std;
ll N, K, arr[300005], dp[300005][2];

inline ll f(int i, int j)
{
    return ((i + 1 >= j) ? 0LL : (arr[j] - arr[(i + 1LL + j) >> 1LL]) - (arr[((i + 1LL + j) >> 1LL) - ((j ^ i) & 1)] - arr[i]));
}

// return i2's left start point
inline ll binary_search(int i1, int i2, int L, int R)
{
    int mid;
    for (int i = 1; i <= 19; ++i)
    {
        int offset = dp[i1][0] - dp[i2][0];
        if (L == R)
            return L;
        mid = (L + R) >> 1LL;
        if (offset + f(i1, mid) >= f(i2, mid))
            R = mid;
        else
            L = mid + 1;
    }
}

int dq[300005][3];
int ldx = 0, rdx = -1;

inline int nextint()
{
    int x = 0, c = getchar(), neg = false;
    while (('0' > c || c > '9') && c != '-' && c != EOF)
        c = getchar();
    if (c == '-')
        neg = true, c = getchar();
    while ('0' <= c && c <= '9')
        x = x * 10 + (c ^ '0'), c = getchar();
    if (neg)
        x = -x;
    return x; // returns 0 if EOF
}

inline ll aliens_search(int N, int K, int L, int R)
{

    dp[0][0] = 0;
    dp[0][1] = 0;
    int mid;
    for (int t = 1; t <= 34; ++t)
    {
        mid = (L + R + 1LL) >> 1LL;

        ldx = 0, rdx = 0;
        dq[0][0] = 0, dq[0][1] = 1, dq[0][2] = N;

        for (int i = 1; i <= N && i <= 300000; ++i)
        {
            while (dq[ldx][2] < i)
                ++ldx;

            dp[i][0] = dp[dq[ldx][0]][0] + f(dq[ldx][0], i) + mid;
            dp[i][1] = dp[dq[ldx][0]][1] + 1;

            int left = N + 1;
            if (rdx - ldx + 1 > 0)
                left = binary_search(dq[rdx][0], i, i, dq[rdx][2] + 1);
            while (rdx - ldx + 1 > 0 && left <= max(i, dq[rdx][1]))
            {
                --rdx;
                if (rdx - ldx + 1 > 0)
                    left = binary_search(dq[rdx][0], i, i, dq[rdx][2] + 1);
            }

            if (rdx - ldx + 1 == 0)
            {
                ++rdx;
                dq[rdx][0] = i, dq[rdx][1] = i, dq[rdx][2] = N;
            }
            else if (left <= N)
            {
                dq[rdx][2] = left - 1;
                ++rdx;
                dq[rdx][0] = i, dq[rdx][1] = left, dq[rdx][2] = N;
            }
        }

        //cout << L << " " << R << " " << mid << " " << dp[N] << " " << tdp[N] << '\n';
        if (dp[N][1] == K || L == R)
            return dp[N][0] - K * mid;
        else if (dp[N][1] < K)
            R = mid - 1;
        else
            L = mid;
    }
}

signed main()
{

    N = nextint();
    K = nextint();
    for (int i = 1; i <= N; i++)
        arr[i] = nextint();
    sort(arr + 1, arr + N + 1);
    for (int i = 2; i <= N; i++)
        arr[i] += arr[i - 1];
    cout << aliens_search(N, K, 0, 3e10) << '\n';
}
