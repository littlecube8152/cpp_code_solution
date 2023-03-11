/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
// #pragma pack(0)
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

int N, M;
vector<int> A;

vector<int> solve(vector<int> v)
{
    if (v.size() == 1)
        return v;
    else
    {
        vector<int> l(v.begin(), v.begin() + v.size() / 2),
            r(v.begin() + v.size() / 2, v.end());
        l = solve(l), r = solve(r);
        for (int i = 0; i < v.size() / 2; i++)
            v[i] = l[i] ^ r[i];
        for (int i = v.size() / 2; i < v.size(); i++)
            v[i] = l[i - v.size() / 2];
        return v;
    }
}

signed main()
{
    fast;
    cin >> N >> M;
    A.resize(N);
    for (int i = 1; i <= N; i++)
        cin >> A[N - i];
    vector<int> ans = {A[0]};
    for (int i = 1; i <= N; i <<= 1)
    {
        A.resize(max((int)A.size(), 2 * i));
        vector<int> cur(A.begin() + i, A.begin() + 2 * i);
        cur = solve(cur);
        ans.resize(2 * i);
        for (int j = 0; j < i; j++)
        {
            ans[j + i] = ans[j];
            ans[j] ^= cur[j];
        }
    }
    for (int i = 1; i <= M; i++)
        cout << ans[(i - 1) % A.size()] << " \n"[i == M];
}
