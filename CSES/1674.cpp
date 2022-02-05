/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    int n, pre[200005] = {}, size[200005], in[200005] = {};
    queue<int> q;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> pre[i];
        in[pre[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        size[i] = 1;
        if (!in[i])
            q.push(i);
    }
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        size[pre[k]] += size[k];
        in[pre[k]]--;
        if (!in[pre[k]])
            q.push(pre[k]);
    }
    for (int i = 1; i <= n; i++)
        cout << size[i] - 1 << " \n"[i == n];
}
