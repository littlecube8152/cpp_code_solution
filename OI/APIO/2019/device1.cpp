#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, A, B;
set<pll> st;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> A >> B;
	for (int i = 1; i <= N; i++)
	{
		ll l, r;
		cin >> l >> r;
		for (ll i = l; i <= r; i++)
			st.insert(pll((i + i/B) % A, i % B));
	}
	cout << st.size() << '\n';
}
