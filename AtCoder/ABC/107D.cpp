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

ll N, bit[200005], a[100005], p[100005];

void init()
{
    for (int i = 1; i <= 2 * N + 1; i++)
        bit[i] = 0;
}

void modify(int pos)
{
    pos += N + 1;
    for (int i = pos; i <= 2 * N + 1; i += (i & -i))
        bit[i]++;
}

int query(int pos)
{
    pos += N + 1;
    int ans = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    int L = 1, R = 1000'000'000;
    while(L < R)
    {
        int mid = (L + R + 1) / 2;
        ll cnt = 0;
        for (int i = 1; i <= N; i++)
            p[i] = p[i - 1] + (a[i] >= mid);
        init();
        modify(0);
        for (int i = 1; i <= N; i++)
        {
            cnt += query(2 * p[i] - i);
            modify(2 * p[i] - i);
        }
        if(2 * cnt >= N * (N + 1) / 2)
            L = mid;
        else
            R = mid - 1;
    }
    cout << L << '\n';
}
