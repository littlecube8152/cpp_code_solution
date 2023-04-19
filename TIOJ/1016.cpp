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

signed main()
{
    fast;
    string s;
    while (cin >> s)
    {
        int score[2] = {}, player = 0, base[3] = {}, out = 0;
        for (char c : s)
        {
            if (c == 'W')
            {
                base[0]++;
                if (base[0] > 1)
                    base[1]++, base[0]--;
                if (base[1] > 1)
                    base[2]++, base[1]--;
                if (base[2] > 1)
                    score[player]++, base[2]--;
            }
            else if (c == 'S')
            {
                score[player] += base[2];
                base[2] = base[1];
                base[1] = base[0];
                base[0] = 1;
            }
            else if (c == 'D')
            {
                score[player] += base[2] + base[1];
                base[2] = base[0];
                base[1] = 1;
                base[0] = 0;
            }
            else if (c == 'T')
            {
                score[player] += base[2] + base[1] + base[0];
                base[2] = 1;
                base[1] = 0;
                base[0] = 0;
            }
            else if (c == 'H')
            {
                score[player] += base[2] + base[1] + base[0] + 1;
                base[2] = 0;
                base[1] = 0;
                base[0] = 0;
            }
            else if (c == 'K' || c == 'O')
            {
                out++;
                if (out == 3)
                {
                    base[0] = base[1] = base[2] = out = 0;
                    player ^= 1;
                }
            }
        }
        cout << score[0] << " " << score[1] << '\n';
    }
}
