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

ll N, T, K, B, W, last = -1e9, ans;
vector<ll> t;
signed main()
{
    cin >> N >> T >> K >> B >> W;
    assert(W == 0);
    last = -K + 1;
    t.resize(N);
    for (int i = 0; i < N; i++)
    {
        ll waste;
        cin >> waste >> t[i] >> waste;
    }
    sort(t.begin(), t.end());
    for(ll i : t)
    {
        last = max(last + K, i);
        if (last <= T)
            ans++;
        else
            break;
    }
    if (ans < B)
        cout << -1 << '\n';
    else
        cout << B << '\n';
}