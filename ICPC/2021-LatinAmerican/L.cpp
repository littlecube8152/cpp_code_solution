#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll mod = 1'000'000'007;
ll N, G, I, E, fac[2000006], ifac[2000006];

ll fpow(ll b, ll p)
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

int calc(ll one, ll zero, bool hasE)
{
	if (I <= zero)
		return I;
	else if (I <= zero + one)
		return zero + hasE;
	else 
		return zero - (I - zero - one) + hasE;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> G >> I >> E;
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= 2 * N; i++)
		fac[i] = fac[i - 1] * i % mod,
		ifac[i] = fpow(fac[i], mod - 2);
	ll ans = 0;
	G = min(G, 2 * N);
	E = min(E, 2 * N - G);
	I = min(I, 2 * N - G - E);
	ll p2 = 1;
	for (ll one = 0; one <= G; one++, p2 = p2 * 2 % mod)
	{
		ll w = G;
		
		if ((G - one) % 2 == 1)
			continue;
		
		ll two = (G - one) / 2, zero = N - one - two;
		
		if (zero < 0)
			continue;
		
		ll p = p2 * fac[N] % mod * ifac[one] % mod * ifac[two] % mod * ifac[N - one - two] % mod;	

		if (E <= one)
		{
		   	w += E;
			w += calc(one - E, zero, 0);
		}
		else if ((E + G) % 2 == 0)
		{
			w += E;
			zero -= (E - one) / 2;
			w += calc(0, zero, 0);
		}
		else
		{
			w += E - 1;
			zero -= (E - one + 1) / 2;
			w += calc(1, zero, 1);
		}

		ans = (ans + w * p) % mod;
	}
	ans = ans * ifac[2 * N] % mod * fac[G] % mod * fac[2 * N - G] % mod;

	cout << ans << '\n';
}
