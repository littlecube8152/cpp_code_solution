#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, K, ans[1000005];

ll p(ll b, ll pow)
{
    if (pow == 1)
        return b;
    else
        return b * p(b, pow - 1);
}

int main()
{
    cin >> N >> K;
    for (ll i = 2; i <= N; i++)
    {
        ll mx = 1;
        for (ll j = 2; j <= sqrt(N); j++)
            for (ll k = 1; k <= 50; k++)
                if (pow(j, k) >= 1e18)
                    break;
                else if(i % p(j, k) == 0)
                    mx = max(k, mx);
                else
                    break;
        ans[mx]++;
    }
    for (int i = 1; i <= K; i++)
        cout << ans[i] << " \n"[i == K];
}
