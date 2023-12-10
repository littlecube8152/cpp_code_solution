#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,fma,popcnt,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

#define i128 __int128

const i128 mod = 9223372036737335297;
const int maxN = 1 << 18;
const i128 pr = 3;

i128 fpow(i128 b, i128 p)
{
	i128 a = 1;
	while (p)
	{
		if (p & 1)
			a = a * b % mod;
		b = b * b % mod;
		p >>= 1;
	}
	return a;
}

struct NTT
{
	i128 w[maxN];
	i128 minv(i128 a) {return fpow(a, mod - 2); }
	NTT()
	{
		i128 dw = fpow(pr, (mod - 1) / maxN);
		w[0] = 1;
		for (int i = 1; i < maxN; i++)
			w[i] = w[i - 1] * dw % mod;
	}
	void bitrev(i128 *a, int n)
	{
		int i = 0;
		for (int j = 1; j < n - 1; j++)
		{
			for (int k = n >> 1; (i ^= k) < k; k >>= 1);
			if(j < i) swap(a[i], a[j]);
		}	
	}

	void operator()(i128 *a, int n, bool inv = false)
	{
		bitrev(a, n);
		for (int L = 2; L <= n; L <<= 1)
		{
			int dx = maxN / L, dl = L >> 1;
			for (int i = 0; i < n; i += L)
				for (int j = i, x = 0; j < i + dl; ++j, x += dx)
				{
					i128 tmp = a[j + dl] * w[x] % mod;
					if ((a[j + dl] = a[j] - tmp) < 0) a[j + dl] += mod;
					if ((a[j] += tmp) >= mod) a[j] -= mod;
				}
		}
		if (inv)
		{
			reverse(a + 1, a + n);
			i128 invn = minv(n);
			for (int i = 0; i < n; i++)
				a[i] = a[i] * invn % mod;
		}
	}
} ntt;

int N;
ll F[100005], C[100005], ans[100005][2];
i128 f[400005], g[400005], h[400005];


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> F[i];
	for (int i = 1; i <= N; i++)
		cin >> C[i];
	for (int t = 1; t >= 0; t--)
	{
		sort(F + 1, F + 1 + N);
		sort(C + 1, C + 1 + N);
		
		vector<ll> same;
		int l = N, r = 1;
		for (int i = 1; i <= N; i++)
		   	if (F[i] * C[i] >= 0)
		   		same.emplace_back(F[i] * C[i]);
			else 
				l = min(l, i), r = max(r, i);	
		if (same.size() < N)
		{
			int M = r - l + 1, K = 1 << (__lg(2 * M - 1) + 1);
			fill(f, f + K, 0);
			fill(g, g + K, 0);
			for (int i = 0; i < M; i++)
				f[i] = abs(F[l + i]),
				g[i] = abs(C[l + i]);
			sort(f, f + M);
			sort(g, g + M);
			ntt(f, K);
			ntt(g, K);
			for (int i = 0; i < K; i++)
				h[i] = f[i] * g[i] % mod;
			ntt(h, K, true);
			i128 pre = 0;
			for (int i = 0; i < M; i++)
			{	
				same.emplace_back(-(h[i] - pre));
				pre = h[i];
			}
		}
		same.emplace_back(1e18);
		sort(same.begin(), same.end(), greater<>());
		for (int i = 1; i <= N; i++)
			ans[i][t] = ans[i - 1][t] + same[i];
		for (int i = 1; i <= N; i++)
			F[i] = -F[i];
	}
	for (int i = 1; i <= N; i++)
		cout << -ans[i][0] << ' ' << ans[i][1] << '\n';
}
