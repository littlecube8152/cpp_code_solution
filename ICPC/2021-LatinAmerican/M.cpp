#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, T[5005], D[5005];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> T[i] >> D[i];
	vector<int> v;
	for (int i = 1; i <= N; i++)
		v.emplace_back(i);
	sort(v.begin(), v.end(), [&](int i, int j) {return D[i] < D[j];});
	// k + sum T <= D
	
	{
		ll sum = 0;
		bool flag = 1;
		for (int i : v)
		{
			sum += T[i];
			if (sum > D[i])
				flag = 0;
		}
		if (!flag)
		{
			cout << "*\n";
			return 0;
		}
	}

	ll sum = 0;
	for (int i = N; i >= 1; i--)
	{
		vector<ll> pre;
		pre.emplace_back(1e10);
		{
			// k + sum <= D
			ll acc = 0;
			for (auto j : v)
			{
				acc += T[j];
				pre.emplace_back(min(pre.back(), D[j] - acc));
			}
		}
		int m = N + 1;

		for (int j = 0; j < i; j++)
		{
			if (sum + T[v[j]] <= pre[j])
				m = min(m, v[j]);
		}
		assert(m <= N);

		cout << m << " \n"[i == 1];
		sum += T[m];
		v.erase(find(v.begin(), v.end(), m));
	}
}
