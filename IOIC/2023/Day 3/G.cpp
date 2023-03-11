#include <bits/extc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;

const int C = 1000000;
ll Q, N, prime[1000006], ans[1000006];

ll fpow(ll p, ll m)
{
    ll a = 1, b = 10 % m;
    while (p)
    {
        if (p & 1)
            a = a * b % m;
        b = b * b % m;
        p >>= 1;
    }
    return a;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i <= C; i++)
        if (!prime[i])
            for (int j = i; j <= C; j += i)
                prime[j] = i;
    cin >> Q;
    while (Q--)
    {
        cin >> N;
        if (N == 1 || N % 2 == 0 || N % 5 == 0)
        {
            cout << -1 << '\n';
            continue;
        }
        int i = N, phi = N;
        while (i > 1)
        {
            int d = prime[i];
            phi = phi / d * (d - 1);
            while (i % d == 0)
                i /= d;
        }
        vector<int> pf;
        i = phi;
        while (i > 1)
        {
            int d = prime[i];
            pf.emplace_back(d);
            while (i % d == 0)
                i /= d;
        }
        for (auto d : pf)
            while (phi % d == 0 && fpow(phi / d, N) == 1)
                phi /= d;
        cout << phi << '\n';
    }
}