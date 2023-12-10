#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

bitset<1005> sol[1005];
ull h[1005];

signed main()
{
	mt19937 rd(49);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--)
	{
		int n, m; 
		bool sw = 0;
		cin >> n >> m;
		
		if ((n * m) % 2 == 1){
			cout << "NO\n";
			continue;
		}
		
		if (m % 2 == 1)
			sw = 1, swap(n, m);
		int p = __lg(m - 1) + 1;
		
		if (n < p)
		{
			cout << "NO\n";
			continue;
		}

		if (m < 14 && n > (1 << m))
		{
			cout << "NO\n";
			continue;
		}

		for (int i = 0; i < m / 2; i++)
		{
			for (int j = 0; j < p; j++)
			{
				sol[j + 1][i] 		  = (i >> j & 1) > 0;
				sol[j + 1][m - i - 1] = (i >> j & 1) == 0; 
			}
		}

		map<ull, bool> mp;

		for (int i = 0; i < m; i++)
			h[i] = (m < 20 ? (1 << i) : rd());
		
		auto gethash = [&](int r)
		{
			ull hs = 0;
			for (int i = 0; i < m; i++)
				hs += sol[r][i] * h[i];
			return hs;
		};

		for (int j = 1; j <= p; j++)
			mp[gethash(j)] = 1;

		if (m >= 14 || (1 << m) / n >= 10)
		{	
			cerr << "random\n";
			int i = p;
			while(i + 2 <= n)
			{
				int cnt = 20;
				while (cnt == 20 || mp[gethash(i + 1)] || mp[gethash(i + 2)])
				{	
					if (cnt-- == 0) break;
					for (int j = 0; j < m; j++)
						sol[i + 2][j] = !(sol[i + 1][j] = rd() % 2);
				}
				if (cnt <= 0)
					break;
				assert(cnt > 0);
				for (int j = 0; j < m; j++)
					sol[i + 2][j] = sol[i + 1][j] ^ 1;
				mp[gethash(i + 1)] = mp[gethash(i + 2)] = 1;
				i += 2;
			}
			vector<int> v(m);
			iota(all(v), 0);
			while(i + 1 <= n)
			{
				i++;
				sol[i] = sol[1];
				while (mp[gethash(i)])
				{
					shuffle(all(v), rd);
					sol[i].reset();
					for (int j = 0; j < m / 2; j++)
						sol[i][v[j]] = 1;
				}
				mp[gethash(i)] = 1;
			}
		}
		else 
		{
			cerr << "brute\n";
			int i = p, k = 0, full = (1 << m) - 1;
			while (i + 2 <= n && (k ^ full) > k)
			{
				while (__builtin_popcount(k) == m / 2)
					++k;
				assert(2 * k <= (1 << m));
				sol[i + 1] = k;
				sol[i + 2] = full ^ k;
				k++;
				i += 2;
			}
			k = 0;
			while (i < n)
			{
				i++;
				while(sol[i] = k, (__builtin_popcount(k) != m / 2 || mp[gethash(i)]))
					k++;
				k++;
				assert(k < (1 << m));
			}
		}

		cout << "YES\n";
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < m; j++)
				cnt += sol[i][j];
		mp.clear();
		for (int i = 1; i <= n; i++)
			assert(!mp[gethash(i)]), mp[gethash(i)] = 1;
		assert(cnt * 2 == n * m);	
		if (sw)
		{
			for (int i = 0; i < m; i++, cout << '\n')
				for (int j = 1; j <= n; j++)
					cout << sol[j][i];
		}
		else
		{
			for (int i = 1; i <= n; i++, cout << '\n')
				for (int j = 0; j < m; j++)
					cout << sol[i][j];
		}
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < m; j++)
				sol[i][j] = 0;

	}
}




