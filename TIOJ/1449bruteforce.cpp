/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
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
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
//using namespace __gnu_pbds;

#define LOCAL

ll N, K, arr[1005], dp[1005][1005];

struct transfer
{
    int i, L, R;
    transfer() : i(0), L(1), R(N){};
    transfer(int i, int L, int R) : i(i), L(L), R(R){};
};

ll cost(int L, int R)
{
    if(L >= R)
        return 0;
    if ((R - L + 1) % 2)
    {
        int mid = (L + R) / 2;
        return (arr[R] - arr[mid]) - (arr[mid - 1] - arr[L - 1]);
    }
    else
    {
        int mid = (L + R) / 2;
        return (arr[R] - arr[mid]) - (arr[mid] - arr[L - 1]);
    }
}

ll f(int k, int i, int j)
{
    return dp[i][k - 1] + cost(i + 1, j);
}

// return i2's left start point
ll binary_search(int k, int i1, int i2, int L, int R)
{
    if (L == R)
        return L;
    int mid = (L + R) / 2;
    if (f(k, i1, mid) >= f(k, i2, mid))
        return binary_search(k, i1, i2, L, mid);
    else
        return binary_search(k, i1, i2, mid + 1, R);
}

signed main()
{
    fast;
    cin >> N >> K;
    for (int i = 2; i <= N; i++)
        cin >> arr[i];
    sort(arr + 2, arr + N + 1);
    for (int i = 3; i <= N; i++)
        arr[i] += arr[i - 1];

    for (int i = 1; i <= N; i++)
        dp[i][0] = 1e10;
    for (int j = 1; j <= K; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            dp[i][j] = 1e10;
            for (int i2 = 0; i2 < i; i2++)
                dp[i][j] = min(f(j, i2, i), dp[i][j]);
        }
    }
    cout << dp[N][K] << '\n';
}
