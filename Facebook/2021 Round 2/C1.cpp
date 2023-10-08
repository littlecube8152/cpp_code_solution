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

int T, R, C, K, ans;
string s[20000005];

signed main()
{
    ifstream cin("valet_parking_chapter_1_input.txt");
    ofstream cout("valet_parking_chapter_1_output.txt");
    fast;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> R >> C >> K;
        ans = C;
        for (int i = 1; i <= R; i++)
            cin >> s[i];
        s[0] = string(C, '.');
        s[R + 1] = string(C, '.');

        int cnt[2000005] = {};
        for (int i = 1; i <= R + 1; i++)
        {
            for (int j = 0; j < C; j++)
                if (s[i][j] == 'X')
                    cnt[j]++;
            if (i >= K)
            {
                int car = 0;
                for (int j = 0; j < C; j++)
                    if (cnt[j] >= K || s[i][j] == 'X')
                        car++;
                ans = min(ans, car + (i - K));
            }
        }

        for (int j = 0; j < C; j++)
            cnt[j] = 0;

        for (int i = R; i >= 0; i--)
        {
            for (int j = 0; j < C; j++)
                if (s[i][j] == 'X')
                    cnt[j]++;
            if (i <= K)
            {
                int car = 0;
                for (int j = 0; j < C; j++)
                    if (cnt[j] >= (R - K + 1) || s[i][j] == 'X')
                        car++;
                ans = min(ans, car + (K - i));
            }
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }
}
