#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int N, M;
ll ans = -1e18, dp[200005], v[200005], c[200005];
pii p[200005];

struct Mset
{
	vector<pair<int, ll>> op;
	multiset<ll> lms, rms;
	ll sum = 0;
	void init(int sz)
	{
		for(int i = 0; i < sz; i++)
			lms.insert(-10'000'000'000'000LL);
		sum = sz * -10'000'000'000'000LL;
	}	
	void insert(ll k)
	{
		lms.insert(k);
		op.emplace_back(pll(0, k));
		sum += k;
		rms.insert(*lms.begin());
		sum -= *lms.begin();
		op.emplace_back(pll(1, *lms.begin()));
		lms.erase(lms.begin());
	}
	void undo(int t)
	{
		while((int)op.size() > t)
		{
			auto [i, k] = op.back();
			op.pop_back();
			if(i == 0)
			{	
				lms.erase(lms.find(k));
				sum -= k;
			}
			else
			{
				rms.erase(rms.find(k));
				lms.insert(k);
				sum += k;
			}
		}
	}
}st;



signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> M;
	M -= 2;
	st.init(M);
	for(int i = 1; i <= N; i++)
		cin >> p[i].S >> p[i].F;
	sort(p + 1, p + 1 + N);
	for(int i = 1; i <= N; i++)
		c[i] = p[i].F, v[i] = p[i].S;
	for(int i = 1; i <= N; i++)
	{
		cerr << i << ":  ";
		st.undo(0);
		for (int j = i - 1; j >= 1; j--)
		{
			cout << j << ' ' << v[j] + v[i] - 2 * (c[i] - c[j]) + st.sum << "  ";
			ans = max(ans, v[j] + v[i] - 2 * (c[i] - c[j]) + st.sum);
			st.insert(v[j]);
		}
		cout << '\n';
	}

	cout << ans << '\n';
}
