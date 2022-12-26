/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define pii128 pair<__int128, __int128>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int N, cnt[2019], pre[200005], ten[200005], ans;
string s;

signed main()
{
    fast;
    cin >> s;
    N = s.size();
    reverse(s.begin(), s.end());
    cnt[0]++;
    ten[0] = 1, pre[0] = s[0] - '0';
    ans += cnt[pre[0]];
    cnt[pre[0]]++;
    for (int i = 1; i < N; i++)
    {
        ten[i] = ten[i - 1] * 10 % 2019;
        pre[i] = (pre[i - 1] + ten[i] * (s[i] - '0')) % 2019;
        ans += cnt[pre[i]];
        cnt[pre[i]]++;
    }
    cout << ans << '\n';
}
