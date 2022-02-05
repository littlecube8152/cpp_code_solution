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
#define fast ios::sync_with_stdio(0LL), cin.tie(0LL)
using namespace std;
//using namespace __gnu_pbds;

int N, ans, st = 1e8, en = 0, idx = 0;
priority_queue<int> pq;
vector<pii> v;

signed main()
{
    fast;
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].F >> v[i].S;
    for (auto i : v)
        st = min(i.F, st), en = max(i.S, en);
    sort(v.begin(), v.end());
    while (st < en)
    {
        while(idx < N && v[idx].F <= st)
            pq.push(v[idx++].S);
        if(pq.empty() || pq.top() < st)
        {
            cout << "NO\n";
            return 0;
        }
        int nxt = pq.top();
        pq.pop();
        ans++;
        st = nxt + 1;
    }
    cout << ans << '\n';
}
