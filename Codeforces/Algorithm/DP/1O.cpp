/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
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

int n, dp[5000005];
vector<int> prime;
signed main()
{                
    fast;
    for (int i = 2; i <= 5000000; i++)
    {
        if (dp[i] == 0)
        {
            prime.pb(i);
            dp[i] = 1;
        }
        for(int j : prime)
        {
            if(i * j > 5000000)
                break;
            dp[i * j] = dp[i] + 1;
            if(i % j == 0)
                break;
        }
    }
    for (int i = 1; i <= 5000000; i++)
        dp[i] += dp[i - 1];
    int a, b;
    cin >> a;
    while(cin >> a >> b)
        cout << dp[a] - dp[b] << '\n';
}
