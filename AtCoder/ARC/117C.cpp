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
// using namespace __gnu_pbds;

int N, frac[400005], three[400005];

int C(int n, int k)
{
    if(three[n] > three[k] + three[n - k])
        return 0;
    else
        return frac[n] * frac[k] * frac[n - k] % 3;
}

signed main()
{
    fast;
    frac[0] = 1;
    for (int i = 1; i <= 400000; i++)
    {
        int j = i;
        three[i] = three[i - 1];
        while(j % 3 == 0)
        {
            j /= 3;
            three[i]++;
        }
        frac[i] = frac[i - 1] * j % 3;
    }
    cin >> N;
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        char c;
        cin >> c;
        sum += (N % 2 == 0 ? -1 : 1) * C(N - 1, i - 1) * (c == 'R' ? 0 : (c == 'B' ? 1 : 2));
    }
    sum %= 3;
    sum += 3;
    sum %= 3;
    cout << (sum == 0 ? "R\n" : (sum == 1 ? "B\n" : "W\n"));
}
