/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
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

int n, m, arr[405][405], cnt[160005], ans;
signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    for (int il = 1; il <= n; il++)
        for (int ir = il; ir <= n; ir++)
        {
            int jl = 1, jr = 0;
            set<int> st;
            while (jr < m)
            {
                jr++;
                for (int i = il; i <= ir; i++)
                {
                    cnt[arr[i][jr]]++;
                    if (cnt[arr[i][jr]] == 2)
                        st.insert(arr[i][jr]);
                }
                while (!st.empty())
                {
                    for (int i = il; i <= ir; i++)
                    {
                        cnt[arr[i][jl]]--;
                        if (cnt[arr[i][jl]] == 1)
                            st.erase(arr[i][jl]);
                    }
                    jl++;
                }
                ans = max(ans, (ir - il + 1) * (jr - jl + 1));
            }
            while (jl <= m)
            {
                for (int i = il; i <= ir; i++)
                    cnt[arr[i][jl]]--;
                jl++;
            }
        }
    cout << ans << '\n';
}