#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int P = 17;
int N;

struct sparse
{
	int table[P][100005];
	void build(int arr[])
	{
		for(int i = 1; i <= N; i++)
			table[0][i] = arr[i];
		for(int p = 0; p + 1 < P; p++)
			for(int i = 1; i <= N - (1 << p); i++)
				table[p + 1][i] = min(table[p][i], table[p][i + (1 << p)]);
	}
	int query(int l, int r)
	{
		int p = __lg(r - l + 1);
		return min(table[p][l], table[p][r - (1 << p) + 1]);
	}
}st;

int Q, rk[100005], order[100005], table[20][100005], last[100005], ans[100005], start[100005];
pii p[100005], range[100005];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> Q;
	for(int i = 1; i <= N; i++)
		cin >> p[i].F >> p[i].S;
	for(int i = 1; i <= N; i++)
		rk[i] = i;
	sort(rk + 1, rk + 1 + N, [&](int i, int j){return p[i].S < p[j].S;});
	for(int i = 1; i <= N; i++)
		order[rk[i]] = i;
	sort(p + 1, p + 1 + N, [&](pii i, pii j){return i.S < j.S; });

	for(int i = 1; i <= N; i++)
		table[0][i] = lower_bound(p + 1, p + 1 + N, pii(0, p[i].F), [](pii i, pii j){return i.S < j.S; }) - p;
	for(int i = 1; i <= N; i++)
		last[i] = upper_bound(p + 1, p + 1 + N, pii(0, p[i].S), [](pii i, pii j){return i.S < j.S; }) - p - 1;
	for(int p = 0; p + 1 < P; p++)
	{
		st.build(table[p]);
		for(int i = 1; i <= N; i++)
			table[p + 1][i] = st.query(table[p][i], last[i]);
	}
	// for(int p = 0; p < P; p++)
	// 	for(int i = 1; i <= N; i++)
	//		cout << table[p][i] << " \n"[i == N];
	
	for(int i = 1; i <= Q; i++)
	{
		int u, v;
		cin >> u >> v;
		if(u == v) ans[i] = -1;
		start[i] = order[u];
		range[i] = pii(order[v], order[v]);
	}
	for(int p = P - 1; p >= 0; p--)
	{
		st.build(table[p]);
		for(int i = 1; i <= Q; i++)
		{
			pii nrange = pii(st.query(range[i].F, range[i].S), last[range[i].S]);
			// if(i == 1 || i == 2) cout << "query " << i << " " << p << " range " << range[i].F << " " << range[i].S << " -> " << nrange.F << " " << nrange.S << '\n';
			if(start[i] < nrange.F || nrange.S < start[i])
			{
				ans[i] += (1 << p);
				range[i] = nrange;
			}
		}
	}
	for(int i = 1; i <= Q; i++)
		if(ans[i] >= N)
			cout << "impossible\n";
		else cout << ans[i] + 1 << '\n';
}
