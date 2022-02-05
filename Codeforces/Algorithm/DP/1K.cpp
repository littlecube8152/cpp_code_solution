/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
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

int n, m, pn = 100, pm = 100, k = 1, cnt;
vector<int> v;
set<pii> st;
signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1, j = 7; i <= 11; i++, j *= 7)
        if (j >= n)
            pn = min(pn, i);
    for (int i = 1, j = 7; i <= 11; i++, j *= 7)
        if (j >= m)
            pm = min(pm, i);

    if (pn + pm > 7)
    {
        cout << 0;
        return 0;
    }
    vector<int> v = {0, 1, 2, 3, 4, 5, 6};

    for (int i = 1; i <= 5040; i++)
    {
        int a = 0, b = 0;
        for (int j = 0; j < pn;j++)
            a = a * 7 + v[j];
        for (int j = pn; j < pn + pm;j++)
            b = b * 7 + v[j];
        if(a < n && b < m)
            st.insert(pii{a, b});
        next_permutation(v.begin(), v.end());
    }
    cout << st.size() << '\n';

   // for(auto i : st)
   //     cout << i.F << " " << i.S << '\n';
}
