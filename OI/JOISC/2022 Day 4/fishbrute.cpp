#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, Q;
ll A[100005], able[100005], mL[100005], mR[100005], sum[100005];

signed main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0), cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> A[i];
	cin >> Q;
	while(Q--)
	{
		int T, L, R;
		cin >> T >> L >> R;
		if(T == 1)
		{
			A[L] = R;
			// continue;
		}

		L = 1, R = N;

		for(int i = 1; i <= N; i++)
			sum[i] = sum[i - 1] + A[i], able[i] = 0;

		vector<int> v;
		for(int i = L; i <= R; i++)
			v.emplace_back(i);
		sort(v.begin(), v.end(), [&](int i, int j){ return A[i] > A[j]; });

		ll inf1 = 1e18, inf2 = 1e18;
		swap(A[L - 1], inf1);
		swap(A[R + 1], inf2);

		int ans = 0;
		set<int> bound;

		for(int i : v)
		{
			auto iter = bound.lower_bound(i);
			if(iter == bound.end() && iter == bound.begin())
			   ans++, able[i] = 1;
			else
			{
				ll l = (iter == bound.begin() ? L - 1 : *prev(iter)),
				   r = (iter == bound.end()   ? R + 1: *iter);
				bool valid = 0;
				if(A[l] <= A[r])
					valid = (sum[r - 1] - sum[l] >= A[l] && able[l]);
				else
					valid = (sum[r - 1] - sum[l] >= A[r] && able[r]);
				ans += valid, able[i] = valid;
			}	

			bound.insert(i);
		}

		swap(A[L - 1], inf1);
		swap(A[R + 1], inf2);
		for(int i = 1; i <= N; i++)
			cout << A[i] << " \n"[i == N];
		for(int i = 1; i <= N; i++)
			cout << able[i] << " \n"[i == N];
	}
	
}
