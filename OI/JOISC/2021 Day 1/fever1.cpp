#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, ans;
pll p[8];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    assert(N <= 7);
    for (int i = 0; i < N; i++)
        cin >> p[i].F >> p[i].S;
    for (int mask = 0; mask < (1 << N); mask++)
        for (int dmask = 0; dmask < (1 << N); dmask++)
        {
            ll dx[8] = {}, dy[8] = {}, t[8];
            int res = 0;
            for (int i = 0; i < N; i++)
            {
                t[i] = 1e18;
                if ((mask >> i) & 1)
                    ((dmask >> i) & 1 ? dx : dy)[i] = 1;
                else
                    ((dmask >> i) & 1 ? dx : dy)[i] = -1;
            }
            t[0] = 0;
            for (int a = 0; a < N; a++)
            {
                int cur = -1;
                for (int i = 0; i < N; i++)
                    if (t[i] >= 0 && t[i] <= 1e17)
                    {
                        if (cur == -1 || t[i] < t[cur])
                            cur = i;
                    }
                if (cur == -1)
                    break;
                res++;
                for (int i = 0; i < N; i++)
                    if (abs(dx[cur]) ^ abs(dx[i]) && abs(dy[cur]) ^ abs(dy[i]) && (p[i].F - p[cur].F) / (dx[cur] - dx[i]) == (p[i].S - p[cur].S) / (dy[cur] - dy[i]) && (p[i].S - p[cur].S) / (dy[cur] - dy[i]) >= t[cur])
                        t[i] = min(t[i], (p[i].F - p[cur].F) / (dx[cur] - dx[i]));
                t[cur] = -1;
            }
            ans = max(ans, res);
        }
    cout << ans << '\n';
}