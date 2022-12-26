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

struct C
{
    int w, x, d;
};

int N, T, L, t[50004], W, ans;
C a[50004];
deque<C> dq;
deque<int> mono;

signed main()
{
    // fast;
    ifstream cin("meetings.in");
    ofstream cout("meetings.out");

    cin >> N >> L;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i].w >> a[i].x >> a[i].d;
        W += a[i].w;
        t[i] = (a[i].d == 1 ? a[i].x - L : a[i].x);
    }
    W = (W + 1) / 2;
    sort(a + 1, a + 1 + N, [&](C c1, C c2)
         { return c1.x < c2.x; });
    sort(t + 1, t + 1 + N, [&](int i1, int i2)
         { return abs(i1) < abs(i2); });
    for (int i = 1; i <= N; i++)
        dq.push_back(a[i]);
    for (int i = 1; i <= N && W > 0; i++)
        if (t[i] > 0)
        {
            W -= dq.front().w;
            T = max(T, abs(t[i]));
            dq.pop_front();
        }
        else
        {
            W -= dq.back().w;
            T = max(T, abs(t[i]));
            dq.pop_back();
        }
    for (int i = 1; i <= N; i++)
    {
        if (a[i].d == 1)
            mono.push_back(a[i].x);
        else
        {
            while(!mono.empty() && a[i].x - mono.front() > 2 * T)
                mono.pop_front();
            ans += mono.size();
        }
    }
    mono.clear();
    cout << ans << '\n';
}