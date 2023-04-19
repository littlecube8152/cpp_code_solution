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
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll INF = 9223372036854775807;
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int N, K;
pll p[305];
set<pii> st;

signed main()
{
    fast;
    cin >> N >> K;
    if (K == 1)
    {
        cout << "Infinity\n";
        return 0;
    }
    for (int i = 1; i <= N; i++)
        cin >> p[i].F >> p[i].S;
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
        {
            vector<int> v;
            for (int k = 1; k <= N; k++)
            {
                ll a = p[i].F - p[k].F, b = p[i].S - p[k].S,
                   c = p[j].F - p[k].F, d = p[j].S - p[k].S;

                if(a * d - b * c == 0)
                    v.emplace_back(k);
            }
            if(v.size() >= K)
                st.insert(pii{v[0], v[1]});
        }
    cout << st.size() << '\n';
}
