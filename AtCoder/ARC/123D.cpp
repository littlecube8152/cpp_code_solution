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
// #define int long long
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

int N;
ll A, B[100005], C[100005];

signed main()
{
    fast;
    cin >> N >> A;
    if (A < 0)
        B[1] = A;
    else
        C[1] = A;
    for (int i = 2; i <= N; i++)
    {
        cin >> A;
        B[i] = B[i - 1];
        C[i] = C[i - 1];
        if (A <= B[i] + C[i])
            C[i] -= abs(B[i] + C[i] - A);
        else
            B[i] += abs(B[i] + C[i] - A);
    }
    A = 0;
    for (int i = 1; i <= N; i++)
        A += abs(B[i]) + abs(C[i]);
    cout << A << '\n';
}
