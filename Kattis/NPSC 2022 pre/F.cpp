#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const ll mod = 998244353;
ll inv(ll b)
{
    ll a = 1, p = mod - 2;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return a;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int a, one = 0;
        for (int i = 1; i <= N; i++)
        {
            cin >> a;
            one += (a == 1);
        }
        
        if(N == 1)
            cout << 1 << '\n';
        else if (one == N)
            cout << (one % 2 == 1 ? 1 : 0) << '\n';
        else if(one == N - 1)
        {
            if(N % 2 == 0)
                cout << inv(2) << '\n';
            else 
                cout << (N / 2 + 1) * inv(N) % mod << '\n';
        }
        else
            cout << inv(2) << '\n';
    }
}