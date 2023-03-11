
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, A[150005], B[150005], C[150005];
vector<int> a, b, c;

signed main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i] >> B[i] >> C[i];
		a.emplace_back(i);
		b.emplace_back(i);
		c.emplace_back(i);
	}
	sort(a.begin(), a.end(), [&](int i, int j)
		 { return A[i] < A[j]; });
	sort(b.begin(), b.end(), [&](int i, int j)
		 { return B[i] < B[j]; });
	sort(c.begin(), c.end(), [&](int i, int j)
		 { return C[i] < C[j]; });

	while (!a.empty() && !b.empty() && !c.empty())
	{
		int i = a.back(), j = b.back(), k = c.back();
		if (B[i] >= B[j] || C[i] >= C[k])
		{
			a.pop_back();
			continue;
		}
		if (A[j] >= A[i] || C[j] >= C[k])
		{
			b.pop_back();
			continue;
		}
		if (A[k] >= A[i] || B[k] >= B[j])
		{
			c.pop_back();
			continue;
		}
		cout << A[i] + B[j] + C[k] << '\n';
		return 0;
	}
	cout << -1 << '\n';
}
