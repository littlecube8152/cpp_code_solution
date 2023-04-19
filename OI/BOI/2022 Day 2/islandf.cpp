#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, s[200005], dsu[200005], rk[200005], sum[200005], the[200005], ans[200005];
vector<int> E[200005], val, idx;
vector<pair<int, pii>> edge;
vector<pii> vertex, undo;

int find(int k)
{
	return k == dsu[k] ? k : find(dsu[k]);
}

void merge(int x, int y)
{
	int rx = find(x), ry = find(y);
	if(rx == ry)
		return;
	if(rk[rx] <= rk[ry])
	{
		rk[ry] += rk[rx];
		sum[ry] += sum[rx];
		dsu[rx] = ry;
		undo.emplace_back(pii(rx, ry));
	}
	else merge(ry, rx);
}

void rollback(int sz)
{
	while(undo.size() > sz)
	{
		//cout << "undo\n";
		auto [x, y] = undo.back();
		undo.pop_back();
		rk[y] -= rk[x];
		dsu[x] = x;
		sum[y] -= sum[x];
		the[x] = the[y];
	}
}

signed main()
{
	cin >> N >> M;
		
	for(int i = 1; i <= N; i++)
	{	
		cin >> s[i];
		val.emplace_back(s[i]);
		vertex.emplace_back(pii(s[i], i));
	}
	
	for(int i = 1; i <= N; i++)
		dsu[i] = i, rk[i] = 1, sum[i] = s[i], the[i] = 1e18;

	sort(val.begin(), val.end(), greater<int>());
	sort(vertex.begin(), vertex.end());
	val.resize(unique(val.begin(), val.end()) - val.begin());

	for(int i = 1; i <= M; i++)
	{
		int u, v;
		cin >> u >> v;
		E[v].emplace_back(u);
		E[u].emplace_back(v);
		edge.emplace_back(make_pair(max(s[u], s[v]), pii(u, v)));
	}	
	
	sort(edge.begin(), edge.end());

	for(int i = 0; i < M; i++)
	{
		idx.emplace_back(undo.size());
		merge(edge[i].S.F, edge[i].S.S);
	}

	for(ll k : val)
	{
		vector<int> strong;
		while(!vertex.empty() && vertex.back().F == k)
		{
			if(k == val.front())
				ans[vertex.back().S] = 1;
			else
			{
				int r = find(vertex.back().S);
				if(the[r] <= sum[r])
					ans[vertex.back().S] = 1;
			}
			if(ans[vertex.back().S] == 1)
				strong.push_back(vertex.back().S);
			vertex.pop_back();
		}
		while(!edge.empty() && edge.back().F == k)
		{
			auto [w, e] = edge.back();
			auto [u, v] = e;
			rollback(idx.back());
			edge.pop_back();
			idx.pop_back();
		}
		for(int i : strong)
		{
			for(int j : E[i])
			{
				int r = find(j);
				the[r] = min(the[r], k);
			}
		}
		//for(int i = 1; i <= N; i++)
		//	cout << "(" << dsu[i] << ", " << rk[i] << ", " << sum[i] << ", " << the[i] << ")" << " \n"[i == N];
	}

	for(int i = 1; i <= N; i++)
		cout << ans[i];
	cout << '\n';
}
