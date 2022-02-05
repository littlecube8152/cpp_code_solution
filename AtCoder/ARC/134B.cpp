/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
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

ll N, arr[26];
string s;

signed main()
{
    fast;
    cin >> N >> s;
    for (int i = 0; i < N; i++)
        arr[s[i] - 'a']++;
    for (int i = 0, j = N - 1; i < j; i++, j--)
    {
        int target = 0;
        for (; target < 26; target++)
            if (arr[target])
                break;
        if (target + 'a' >= s[i])
        {
            arr[s[i] - 'a']--;
            j++;
            continue;
        }
        for (; j > i; j--)
        {
            arr[s[j] - 'a']--;
            if (s[j] == target + 'a')
                break;
        }
        arr[s[i] - 'a']--;
        swap(s[i], s[j]);
    }
    cout << s << '\n';
}
