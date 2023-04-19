#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

struct event
{
    ll c, s, v;
};

ll N, T, K, B, W, last = -1e9, Bans, Wans;
vector<pll> t;
signed main()
{
    cin >> N >> T >> K >> B >> W;
    last = -K + 1;
    t.resize(N);
    for (int i = 0; i < N; i++)
    {
        ll waste;
        cin >> t[i].S >> t[i].F >> waste;
    }
    sort(t.begin(), t.end());
    for (pll i : t)
    {
        if ((i.S == 0 && Bans < B) || (i.S == 1 && Wans < W))
        {
            last = max(last + K, i.F);
            if (last <= T)
            {
                if (i.S == 0)
                    Bans++;
                else
                    Wans++;
            }
            else
                break;
        }
    }
    if (Bans < B || Wans < W)
        cout << -1 << '\n';
    else
        cout << B + W << '\n';
}