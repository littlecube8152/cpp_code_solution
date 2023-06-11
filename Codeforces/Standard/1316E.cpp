/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC comment(linker,"/stack:200000000")
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
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct P
{
    ll id, a, s[7];
};

ll n, p, k, b[7][14];
P arr[100005];

ll dfs(int c[7], int pos, int ptr, ll value)
{
    ll res = 0;
    if (pos >= p)
    {
        //for (int i = 0; i < p;i++)
        //    cout << c[i] << " ";  
        //cout << value << '\n';
        return value;
    }

    ll __ptr = ptr, __value = value;
    for (int i = 0; i < min(2 * p, n); i++)
    {
        ptr = __ptr, value = __value;
        c[pos] = b[pos][i];

        bool check = 1;
        for (int i = 0; i < pos; i++)
            if (c[i] == c[pos])
                check = 0;
        if (!check)
            continue;

        value += arr[c[pos]].s[pos];
        if (arr[c[pos]].id <= ptr)
        {
            ptr++;
            value += arr[ptr].a - arr[c[pos]].a;
            while (c[0] == ptr || c[1] == ptr || c[2] == ptr || c[3] == ptr || c[4] == ptr || c[5] == ptr || c[6] == ptr)
            {
                value += arr[ptr + 1].a - arr[c[ptr]].a;
                ptr++;
            }
        }
        res = max(res, dfs(c, pos + 1, ptr, value));
    }
    return res;
}

signed main()
{
    cin >> n >> p >> k;

    for (int i = 1; i <= n; i++)
        cin >> arr[i].a;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < p; j++)
            cin >> arr[i].s[j];

    sort(arr + 1, arr + n + 1, [](P a, P b) { return a.a > b.a; });
    for (int i = 1; i <= n; i++)
        arr[i].id = i;

    for (int i = 0; i < p; i++)
    {
        sort(arr + 1, arr + n + 1, [&](P a, P b) { return a.s[i] - (a.id <= k ? 1 : 0) * a.a > b.s[i] - (b.id <= k ? 1 : 0) * b.a; });
        for (int j = 0; j < min(2 * p, n); j++)
            b[i][j] = arr[j + 1].id;
    }
    sort(arr + 1, arr + n + 1, [](P a, P b) { return a.a > b.a; });
    int c[7] = {0, 0, 0, 0, 0, 0, 0};
    ll value = 0;
    for (int i = 1; i <= k; i++)
        value += arr[i].a;

    cout << dfs(c, 0, k, value);
}
