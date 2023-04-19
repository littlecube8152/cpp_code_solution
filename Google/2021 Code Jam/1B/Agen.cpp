/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int t;

int check(int a, int b, int c, int h, int m)
{
    int H = 3600000000000LL * h, M = 60000000000LL * m;
    if((- a + H + b) % (11) )
        return -1;
    int ns1 = (- a + H + b) / (11) - M,
        ns2 = (b - c + M * 708LL) / (-708);

    //cout << "S may be " << ns1 << " " << ns2 << '\n';
    if (ns1 == ns2)
        return ns1;
    return -1;
}

void solve(vector<ll> v, int test)
{
    for (int i = 1; i <= 6; i++)
    {
        next_permutation(v.begin(), v.end());
        for (int h = 0; h < 12; h++)
            for (int m = 0; m < 60; m++)
            {
                int ans = check(v[0], v[1], v[2], h, m);
                if (ans >= 0)
                {
                    cout << "Case #" << test << ": " << h << " " << m << " " << ans / 1000000000LL << " " << ans % 1000000000LL << '\n';
                    return;
                }
            }
    }
    cout << "Case #" << test << ": IMPOSSIBLE\n";
}

signed main()
{
    //fast;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int h, m, s, n;
        cin >> h >> m >> s >> n;
        int t = (h * 3600000000000LL + m * 60000000000LL + s * 1000000000LL + n);
        cout << t << " " << t % 3600000000000LL << " " << t % 60000000000LL << '\n';
    }
}
