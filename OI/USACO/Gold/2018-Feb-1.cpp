/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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

struct S
{
    int i, d, s, t;
};

int N, Q, ans[100005];
vector<S> v;
set<int> arr;
multiset<int, greater<int>> st;

signed main()
{
    ifstream cin("snowboots.in");
    ofstream cout("snowboots.out");
    fast;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        int d;
        cin >> d;
        v.emplace_back(S{i, d, 0, 0});
    }
    for (int i = 1; i <= Q; i++)
    {
        int s, d;
        cin >> d >> s;
        v.emplace_back(S{i, d, s, 1});
    }
    sort(v.begin(), v.end(), [](S s1, S s2)
         { return make_pair(s1.d, s1.t) < make_pair(s2.d, s2.t); });
    arr.insert(0);
    arr.insert(N + 1);
    st.insert(N + 1);
    for (auto [i, d, s, t] : v)
    {
        if (t == 0)
        {
            auto nxt = arr.upper_bound(i), pre = prev(nxt);
            st.erase(st.find(*nxt - *pre));
            st.insert(i - *pre);
            st.insert(*nxt - i);
            arr.insert(i);
        }
        else
            ans[i] = (*st.begin() <= s ? 1 : 0);
    }
    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';
}