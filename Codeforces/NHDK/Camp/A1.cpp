/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const ll mod = MOD;
const ll inv26 = 729486258;

ll p, n, m, k;
ll brute(int cur, int score)
{
    if(cur == p)
        return score + mod;
    else 
    {
        ll sum = 0;
        for (int i = 1; i <= 26; i++)
            if (i <= n)
                sum += brute(cur + 1, 1);
            else if(i <= n + m)
                sum += brute(cur + 1, -1);
            else if(i <= n + m + k)
                sum += brute(cur + 1, -score);
            else
                sum += brute(cur + 1, score);
        return (sum % mod) * inv26 % mod;
    }
}

signed main()
{
    fast;
    char c;
    cin >> p >> n;
    for (int i = 1; i <= n; i++)
        cin >> c;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> c;
    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> c;
    cout << (brute(0, 1) + mod) % mod;
}
