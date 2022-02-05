/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
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
//using namespace __gnu_pbds;

#define LOCAL
ll N, a, b, c, s[1000005], dp[1000005];

struct line
{
    ll a, b;
    line() : a(0), b(0){};
    line(ll a, ll b) : a(a), b(b){};
    ll operator()(ll x)
    {
        return a * x + b;
    }
    ll operator&(line l)
    {
        return (l.b - b) / (a - l.a);
    }
};

signed main()
{
    fast;
    cin >> N >> a >> b >> c;
    for (int i = 1; i <= N; i++)
        cin >> s[i];
    for (int i = 1; i <= N; i++)
        s[i] += s[i - 1];
    deque<line> dq;
    dq.push_front(line(b, 0));
    for (int i = 1; i <= N; i++)
    {
        while (dq.size() >= 2 && dq[0](s[i]) <= dq[1](s[i]))
            dq.pop_front();
        dp[i] = dq[0](s[i]) + a * s[i] * s[i] + c;
        line l(b - 2LL * a * s[i], a * s[i] * s[i] - b * s[i] + dp[i]);
        while (dq.size() >= 2 && (dq[dq.size() - 1] & dq[dq.size() - 2]) >= (dq[dq.size() - 1] & l))
            dq.pop_back();
        dq.push_back(l);
    }
    cout << dp[N] << '\n';
}
