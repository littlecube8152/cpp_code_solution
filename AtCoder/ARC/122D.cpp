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

int N;
vector<int> v;

int minxor(vector<int> &u, vector<int> &v, int bit)
{
    if (u.size() == 0 || v.size() == 0)
        return 1 << 30;
    if (bit == 0)
        return u[0] ^ v[0];
    vector<int> lu, lv, ru, rv;
    for (int i : u)
        if (i & bit)
            ru.emplace_back(i);
        else
            lu.emplace_back(i);
    for (int i : v)
        if (i & bit)
            rv.emplace_back(i);
        else
            lv.emplace_back(i);
    if ((lu.size() == 0 || lv.size() == 0) && (ru.size() == 0 || rv.size() == 0))
        return minxor(u, v, bit >> 1);
    else
        return min(minxor(lu, lv, bit >> 1), minxor(ru, rv, bit >> 1));
}

int divide(vector<int> &v, int bit = (1 << 30))
{
    if (v.empty())
        return 0;
    //  cout << bit << " [";
    //  for (int i : v)
    //      cout << i << ", ";
    //  cout << "]\n";
    if (bit == 0)
        return 0;
    vector<int> has, no;
    for (int i : v)
        if (i & bit)
            has.emplace_back(i);
        else
            no.emplace_back(i);
    if (has.size() % 2 == 0)
        return max(divide(has, bit >> 1), divide(no, bit >> 1));
    return minxor(has, no, bit >> 1);
}

signed main()
{
    fast;
    cin >> N;
    N *= 2;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    cout << divide(v) << '\n';
}

// 00001
// 00111
// 00110
// 00101
// 01001
// 01000
