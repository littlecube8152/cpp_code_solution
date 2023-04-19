#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, Q;
ll S[200005], ans;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++)
	{	
		cin >> S[i];
		ans += ((i == 1 || i == N) ? 1 : 2) * S[i];
	}
	vector<int> mono;
	for (int i = 1; i <= N; i++)
	{
		while(!mono.empty() && mono.back() < S[i])
			mono.pop_back();
		if(!mono.empty())
			ans -= S[i];
		mono.emplace_back(S[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		while(!mono.empty() && mono.back() < S[i])
			mono.pop_back();
		if(!mono.empty())
			ans -= S[i];
		mono.emplace_back(S[i]);
	}

	cout << ans << '\n';
}
