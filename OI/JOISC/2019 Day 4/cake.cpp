#pragma GCC optimize("Ofast,unroll-loops")
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
	priority_queue<ll, vector<ll>, greater<ll>> lms, rms;
	ll sum = 0;
	void init(int sz)
	{
		for(int i = 0; i < sz; i++)
			lms.push(-10'000'000'000'000LL);
		sum = sz * -10'000'000'000'000LL;
	}	
	void insert(ll k)
	{
		while(!rms.empty() && rms.top() == lms.top())
		{
			rms.pop();
			lms.pop();
		}
		lms.push(k);
		op.emplace_back(pll(0, k));
		sum += k;
		sum -= lms.top();
		op.emplace_back(pll(1, lms.top()));
		lms.pop();
	}
	void undo(int t)
	{
		while((int)op.size() > t)
		{
			auto [i, k] = op.back();
			op.pop_back();
			if(i == 0)
			{	
				rms.push(k);
				sum -= k;
			}
			else
			{
				lms.push(k);
				sum += k;
			}
		}
		while(!rms.empty() && rms.top() == lms.top())
		{
			rms.pop();
			lms.pop();
		}
	}
}st;



// Assume (qR, L) is already in the set
void solve(int L, int R, int qL, int qR)
{
	int mid = (L + R) / 2;
	if(R < L)
		return;
	
	//cerr << L << ' ' << R << " -> " << qL << ' ' << qR << '\n'; 
	int initT = st.op.size();
	
	for (int i = mid - 1; i > qR && i >= L; i--)
		st.insert(v[i]);
	
	for (int i = min(mid - 1, qR); i >= qL; i--)
	{
		dp[i] = st.sum + v[mid] + v[i] - 2 * (c[mid] - c[i]);
		st.insert(v[i]);
	}

	st.undo(initT);

	int qMid = qL;
	for (int i = min(mid - 1, qR); i >= qL; i--)
		if(dp[i] >= dp[qMid])
			qMid = i;

	ans = max(dp[qMid], ans);
	
	// cerr << "calc " << mid << ' ' << st.rms.size() << '\n';
	// cerr << mid << ' ' << qMid << ' ' << dp[qMid] << '\n';
	
	
	if (L <= mid - 1)
	{

		for (int i = min(L - 1, qR); i > qMid; i--)
			st.insert(v[i]);

		solve(L, mid - 1, qL, qMid);

		st.undo(initT);
	}

	if (mid + 1 <= R)
	{
		for (int i = max(qR + 1, L); i <= mid; i++)
			st.insert(v[i]);

		solve(mid + 1, R, qMid, qR);

		st.undo(initT);
	}
}	


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
	solve(1, N, 1, N);
	cout << ans << '\n';
}
