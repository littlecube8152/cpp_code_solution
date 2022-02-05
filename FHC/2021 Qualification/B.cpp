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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int T, N;
string s[60];

signed main()
{
    //ifstream cin("xs_and_os_input.txt");
    //ofstream cout("xs_and_os_output.txt");
    fast;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        bool one[60][60] = {{}};
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> s[i];

        int ans[60] = {};
        for (int i = 0; i < N; i++)
        {
            bool valid = true;
            int dot = 0, lastdot;
            for (int j = 0; j < N; j++)
                if (s[i][j] == 'O')
                    valid = false;
                else if (s[i][j] == '.')
                    dot++, lastdot = j;
            if (valid)
            {
                ans[dot]++;
                if (dot == 1)
                    one[i][lastdot] = true;
            }
        }
        for (int i = 0; i < N; i++)
        {
            bool valid = true;
            int dot = 0, lastdot;
            for (int j = 0; j < N; j++)
                if (s[j][i] == 'O')
                    valid = false;
                else if (s[j][i] == '.')
                    dot++, lastdot = j;
            if (valid)
            {
                if (dot == 1 && one[lastdot][i])
                    continue;
                ans[dot]++;
            }
        }
        pii out = {-1, -1};
        for (int i = 1; i <= N; i++)
            if (ans[i] > 0)
            {
                out = {i, ans[i]};
                break;
            }
        if (out.F == -1)
            cout << "Case #" << t << ": Impossible\n";
        else
            cout << "Case #" << t << ": " << out.F << " " << out.S << '\n';
    }
}
