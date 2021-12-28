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


int ans = 0;
int location[8];
string grid[8];

void solve(int idx)
{
    if (idx == 8)
    {
        ans += 1;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (grid[idx][i] == '*')
            continue;
        else
        {
            for (int j = 0; j < idx; j++)
                if (abs(idx - j) == abs(i - location[j]) || location[j] == i)
                    goto jump;
            location[idx] = i;
            solve(idx + 1);
            location[idx] = 0;
        }
    jump:
        continue;
    }
}

signed main()
{
    fast;
    for (int i = 0; i < 8; i++)
        cin >> grid[i];
    solve(0);
    cout << ans;
}
