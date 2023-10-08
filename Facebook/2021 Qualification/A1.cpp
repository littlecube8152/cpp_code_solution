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

bool is_vowel(char c)
{
    return (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U');
}

int T;
string s;

signed main()
{
    ifstream cin("consistency_chapter_1_input.txt");
    ofstream cout("consistency_chapter_1_output.txt");
    fast;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> s;
        int ans = 9000;
        for (int i = 'A'; i <= 'Z'; i++)
        {
            int res = 0;
            for (char c : s)
            {
                if (c == (char)i)
                    res += 0;
                else if (is_vowel(c) ^ is_vowel((char)i))
                    res += 1;
                else
                    res += 2;
            }
            ans = min(ans, res);
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }
}
