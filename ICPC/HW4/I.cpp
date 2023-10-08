#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 998244353;
ll fpow(ll b, ll p)
{
    ll a = 1;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        p >>= 1;
        b = b * b % mod;
    }
    return a;
}

ll inv(ll b)
{
    return fpow(b, mod - 2);
}

ll N, K, A[100005];

signed main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
}