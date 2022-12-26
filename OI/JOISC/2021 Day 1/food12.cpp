#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, Q;
deque<pll> v[2005];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> Q;
    for (int i = 1; i <= Q; i++)
    {
        ll T, L, R, C, K;
        cin >> T >> L >> R;
        if (T == 1)
        {
            cin >> C >> K;
            for (int j = L; j <= R; j++)
                v[j].emplace_back(pll{K, C});
        }
        else if (T == 2)
        {
            cin >> K;
            for (int j = L; j <= R; j++)
            {
                ll rem = K;
                while (!v[j].empty() && rem > 0)
                {
                    if (v[j].front().F > rem)
                    {
                        v[j].front().F -= rem;
                        rem = 0;
                    }
                    else if (v[j].front().F <= rem)
                    {
                        rem -= v[j].front().F;
                        v[j].pop_front();
                    }
                }
            }
        }
        else if(T == 3)
        {
            ll rem = R, ans = 0;
            for(auto [cnt, c] : v[L])
            {
                if(rem <= cnt)
                {
                    ans = c;
                    break;
                }
                else
                    rem -= cnt;
            }
            cout << ans << '\n';
        }
    }
}