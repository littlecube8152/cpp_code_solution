/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/extc++.h>
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
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
//using namespace __gnu_pbds;

#define LOCAL

const ll mod = 1e9 + 7;
int A, C, M, usedC, usedM;
ll ans, fac[400005] = {1};

ll fastpow(ll b, ll p)
{
    ll a = 1;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return a;
}

auto inv = [](ll a)
{ return fastpow(a, mod - 2); };

ll binom(int a, int b)
{
    return (fac[a] * inv(fac[b]) % mod) * inv(fac[a - b]) % mod;
}

ll H(int a, int b)
{
    if (b < 0)
        return 0;
    return binom(a + b - 1, b);
}

signed main()
{
    for (int i = 1; i <= 400000; i++)
        fac[i] = fac[i - 1] * i % mod;
    cin >> A >> C >> M;
    for (int i = 0; i <= A + 1; i++)
    {
        if (C != M)
            goto end;
        //Case 1: A..A..A
        if (i <= A - 1)
        {
            int usedCM = A - 1 - usedC - usedM,
                remCM = C - usedCM;
            //printf("case 1  %d C  %d M  %d CM  %d freeCM\n", usedC, usedM, usedCM, remCM);
            ans = (ans + (((((fastpow(2, usedCM) * fac[A - 1] % mod) * inv(fac[usedC]) % mod) * inv(fac[usedM]) % mod) * inv(fac[usedCM]) % mod) * H(A - 1, remCM) % mod)) % mod;
        }
        //Case 2: ..A..A..A or A..A..A..
        if (i <= A)
        {
            int usedCM = A - usedC - usedM,
                remCM = C - usedCM;

            //printf("case 2  %d C  %d M  %d CM  %d freeCM\n", usedC, usedM, usedCM, remCM);
            ans = (ans + (((((fastpow(2, usedCM + 1) * fac[A] % mod) * inv(fac[usedC]) % mod) * inv(fac[usedM]) % mod) * inv(fac[usedCM]) % mod) * H(A, remCM) % mod)) % mod;
        }
        //Case 2: ..A..A..A..
        if (i <= A + 1)
        {
            int usedCM = A + 1 - usedC - usedM,
                remCM = C - usedCM;
            //printf("case 3  %d C  %d M  %d CM  %d freeCM\n", usedC, usedM, usedCM, remCM);
            ans = (ans + (((((fastpow(2, usedCM) * fac[A + 1] % mod) * inv(fac[usedC]) % mod) * inv(fac[usedM]) % mod) * inv(fac[usedCM]) % mod) * H(A + 1, remCM) % mod)) % mod;
        }
        end:
        if (C >= M)
        {
            C--;
            usedC++;
        }
        else
        {
            M--;
            usedM++;
        }
    }
    cout << ans << '\n';
}
