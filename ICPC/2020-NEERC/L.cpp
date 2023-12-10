#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;


int N;
vector<int> of(vector<int> u, vector<int> v)
{
	vector<int> w(N);
	for (int i = 0; i < N; i++)
		w[i] = v[u[i]];
	return w;
}

void solve()
{
	cin >> N;

	vector<int> f(N), g(N), p(N), q(N), ans(N), pi(N), ipi(N);

	if (N % 2 == 1)
	{		
		for (int i = 0; i < N; i++)
			f[i] = 2 * i % N, g[i] = (i + N - 1) % N;
#ifdef LOCAL
		for (int i = 0; i < N; i++)
			cin >> pi[i], pi[i]--, ipi[pi[i]] = i;
		p = of(of(ipi, f), pi);
		q = of(of(ipi, g), pi);
#else
		cout << '?';
		for (int i = 0; i < N; i++)
			cout << ' ' << f[i] + 1;
		cout << endl;
		for (int i = 0; i < N; i++)
			cin >> p[i], p[i]--;
		cout << '?';
		for (int i = 0; i < N; i++)
			cout << ' ' << g[i] + 1;
		cout << endl;
		for (int i = 0; i < N; i++)
			cin >> q[i], q[i]--;
#endif
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				if (p[j] == j) ans[i] = j;
			p = of(p, q);
		}
		cout << '!';
		for (int i = 0; i < N; i++)
			cout << ' ' << ans[i] + 1;
		cout << endl;
	}
	else
	{
		for (int i = 0; i < N - 1; i++)
			f[i] = 2 * i % (N - 1), g[i] = (i + N - 2) % (N - 1);
		f[N - 1] = g[N - 1] = N - 1;

#ifdef LOCAL
		for (int i = 0; i < N; i++)
			cin >> pi[i], pi[i]--, ipi[pi[i]] = i;
		p = of(of(ipi, f), pi);
		q = of(of(ipi, g), pi);
#else
		cout << '?';
		for (int i = 0; i < N; i++)
			cout << ' ' << f[i] + 1;
		cout << endl;
		for (int i = 0; i < N; i++)
			cin >> p[i], p[i]--;
		cout << '?';
		for (int i = 0; i < N; i++)
			cout << ' ' << g[i] + 1;
		cout << endl;
		for (int i = 0; i < N; i++)
			cin >> q[i], q[i]--;
#endif
		for (int j = 0; j < N; j++)
			if (q[j] == j) ans[N - 1] = j;
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < N; j++)
				if (p[j] == j && q[j] != j) ans[i] = j;
			p = of(p, q);
		}
		cout << '!';
		for (int i = 0; i < N; i++)
			cout << ' ' << ans[i] + 1;
		cout << endl;

	}






}



signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--)
		solve();
}

