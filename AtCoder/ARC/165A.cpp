#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mul(__int128 a, __int128 b, __int128 c)
{
    return a * b % c;
}

// n < 4,759,123,141      3 : 2, 7, 61
// n < 1,122,004,669,633  4 : 2, 13, 23, 1662803
// n < 3,474,749,660,383  6 : pirmes <= 13
// n < 2^64             7 : 
// 2, 325, 9375, 28178, 450775, 9780504, 1795265022
bool Miller_Rabin(ll a, ll n) {
  if ((a = a % n) == 0) return 1;
  if (n % 2 == 0) return n == 2;
  ll tmp = (n - 1) / ((n - 1) & (1 - n));
  ll t = __lg(((n - 1) & (1 - n))), x = 1;
  for (; tmp; tmp >>= 1, a = mul(a, a, n))
    if (tmp & 1) x = mul(x, a, n);
  if (x == 1 || x == n - 1) return 1;
  while (--t)
    if ((x = mul(x, x, n)) == n - 1) return 1;
  return 0;
}

bool prime(ll x)
{
    bool flag = 1;
    for (ll k : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
        flag &= Miller_Rabin(k, x);
    return flag;
}

vector<ll> f;

void PollardRho(ll n) {
  if (n == 1) return;
  if (prime(n)) return f.emplace_back(n), void();        
  if (n % 2 == 0) return PollardRho(n / 2), f.emplace_back(2), void();
  ll x = 2, y = 2, d = 1, p = 1;
  #define f(x, n, p) ((mul(x, x, n) + p) % n)
  while (true) {
    if (d != n && d != 1) {
      PollardRho(n / d);
      PollardRho(d);
      return;
    }
    if (d == n) ++p;
    x = f(x, n, p), y = f(f(y, n, p), n, p);
    d = gcd(abs(x - y), n);
  }
}


signed main()
{
    int T;
    ll N;
    cin >> T;
    while(T--)
    {
        cin >> N;
        f.clear();
        PollardRho(N);
        sort(f.begin(), f.end());
        f.resize(unique(f.begin(), f.end()) - f.begin());
        puts(f.size() >= 2 ? "Yes" : "No");
    }
}