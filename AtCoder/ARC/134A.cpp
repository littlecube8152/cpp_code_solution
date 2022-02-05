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

ll N, ans, arr[100005];
ll L, W;

signed main()
{
    fast;
    cin >> N >> L >> W;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    arr[N + 1] = L;
    arr[N + 2] = 5e18;
    ll cur = 0, ldx = 1, done = -1;
    while(cur < L)
    {
        //cout << cur << " " << ans << " " << done << '\n';
        if(done <= cur)
        {
            ans += (arr[ldx] - cur + W - 1) / W;
            cur += ((arr[ldx] - cur + W - 1) / W) * W;
            while(arr[ldx] <= cur)
            {
                done = arr[ldx] + W;
                ldx++;
            }
        }
        else
            cur = done;
    }
    cout << ans << '\n';
}
