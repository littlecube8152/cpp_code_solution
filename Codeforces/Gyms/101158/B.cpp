/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
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

int n, m, arr[10][10];

int chkdgt(int a, int b, int c, int d)
{
    return arr[arr[arr[arr[0][a]][b]][c]][d];
}

bool chkpwd(int a, int b, int c, int d, int e)
{
    return (arr[chkdgt(a, b, c, d)][e] == 0 ? 1 : 0);
}

signed main()
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> arr[i][j];

#define rep(a) for (int a = 0; a < 10; a++)

    rep(a) rep(b) rep(c) rep(d)
    {
        int e = chkdgt(a, b, c, d);

        if ((chkpwd(b, a, c, d, e) && a != b) ||
            (chkpwd(a, c, b, d, e) && b != c) ||
            (chkpwd(a, b, d, c, e) && c != d) ||
            (chkpwd(a, b, c, e, d) && d != e))
            n++;
        else
        {
            rep(f) if ((chkpwd(f, b, c, d, e) && f != a) ||
                       (chkpwd(a, f, c, d, e) && f != b) ||
                       (chkpwd(a, b, f, d, e) && f != c) ||
                       (chkpwd(a, b, c, f, e) && f != d) ||
                       (chkpwd(a, b, c, d, f) && f != e))
            {
                n++;
                f = 10;
            }
        }
    }
    cout << n + m << '\n';
}
