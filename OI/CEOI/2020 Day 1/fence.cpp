#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll MOD = 1000000007;
const ll inv2 = 500000004;

int N;
ll h[100005], w[100005], ans;
vector<pll> mono = {pll{0, 0}};

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> h[i];
    for (int i = 1; i <= N; i++)
        cin >> w[i];
    N++;
    for (int i = 1; i <= N; i++)
    {

        while (h[i] < mono.back().F)
        {
            if (h[i] < mono[mono.size() - 2].F)
            {
                ans = (ans + (((((mono.back().S * (mono.back().S + 1) % MOD) * inv2 % MOD) * (mono[mono.size() - 1].F - mono[mono.size() - 2].F) % MOD) * (mono[mono.size() - 1].F + mono[mono.size() - 2].F + 1) % MOD) * inv2 % MOD)) % MOD;
                mono[mono.size() - 2].S = (mono.back().S + mono[mono.size() - 2].S) % MOD;
            }
            else
            {
                ans = (ans + (((((mono.back().S * (mono.back().S + 1) % MOD) * inv2 % MOD) * (mono[mono.size() - 1].F - h[i]) % MOD) * (mono[mono.size() - 1].F + h[i] + 1) % MOD) * inv2 % MOD)) % MOD;
                w[i] = (mono.back().S + w[i]) % MOD;
            }

            mono.pop_back();
            //for (pll i : mono)
            //    cout << "(" << i.F << ", " << i.S << ") ";
            //cout << " | " << ans << '\n';
        }
        if (h[i] == mono.back().F)
            mono.back().S = (mono.back().S + w[i]) % MOD;
        else
            mono.emplace_back(pll{h[i], w[i]});

        //for (pll i : mono)
        //    cout << "(" << i.F << ", " << i.S << ") ";
        //cout << " | " << ans << '\n';
    }
    cout << ans << '\n';
}