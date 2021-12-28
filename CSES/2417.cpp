/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
//#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
//using namespace __gnu_pbds;

//#define LOCAL

int N, cnt[1000005], res, m[1000005];
bitset<1000005> b;
vector<int> p;
signed main()
{
    fast;
    m[0] = 0;
    m[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        if (!b[i])
        {
            p.emplace_back(i);
            m[i] = -1;
        }
        for (int j : p)
        {
            if (i * j > 1000000)
                break;
            b[i * j] = 1;
            if (i % j == 0)
            {
                m[i * j] = 0;
                break;
            }
            else
                m[i * j] = -m[i];
        }
    }
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int j;
        cin >> j;
        cnt[j]++;
    }
    for (int i = 1; i <= 1000000; i++)
    {
        int c = 0;
        for (int j = i; j <= 1000000; j += i)
            c += cnt[j];
        res += c * (c - 1) / 2 * m[i];
    }
    cout << res << '\n';
}