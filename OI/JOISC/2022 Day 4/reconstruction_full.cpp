#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, Q, dsu[505], rk[505];
pii E[100005];
ll w[100005], q[1000006], ans[1000006], lazy[1000006], use[100005];
vector<int> mst[1000006];


inline int find(int k)
{
	return k == dsu[k] ? k : dsu[k] = find(dsu[k]);
}

bool merge(int u, int v)
{
	int ru = find(u), rv = find(v);
	if(ru == rv)
		return 0;
	if(rk[ru] < rk[rv])
		swap(ru, rv);
	dsu[rv] = ru;
	rk[ru] += rk[rv];
	return 1;
}

void MST(int qdx, vector<int> &edx, bool keep = 0)
{
	if(!mst[qdx].empty())
		return;
	for(int i = 1; i <= N; i++)
		dsu[i] = i, rk[i] = 1;
	sort(edx.begin(), edx.end(), [&](int i, int j){ return make_pair(abs(q[qdx] - w[i]), i) < make_pair(abs(q[qdx] - w[j]), j); });
	int cnt = N - 1;
	for(auto i : edx)
	{
		if(merge(E[i].F, E[i].S))
		{
			mst[qdx].emplace_back(i);
			cnt--;
			if(keep) use[i] = 1;
		}
		if(!cnt) break;
	}
	sort(mst[qdx].begin(), mst[qdx].end(), [&](int i, int j){ return make_pair(w[i], i) < make_pair(w[j], j); });
}

void bs(int L, int R, vector<int> &v)
{
	if(mst[L] == mst[R])
		return;
	
	int mid = (L + R) / 2;
	vector<int> u;

	MST(mid, v, 1);
	for(int i : v)
		if(use[i] || w[i] <= q[mid])
		{	
			u.emplace_back(i);
			use[i] = 0;
		}
	bs(L, mid, u);
	u.clear();

	MST(mid + 1, v, 1);
	for(int i : v)
		if(use[i] || w[i] >= q[mid + 1])
		{	
			u.emplace_back(i);
			use[i] = 0;
		}
	bs(mid + 1, R, u);
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= M; i++)
		cin >> E[i].F >> E[i].S >> w[i];

	cin >> Q;
	vector<int> v;
	for(int i = 1; i <= M; i++)
		v.emplace_back(i);

	for(int i = 1; i <= Q; i++)
	{	
		cin >> q[i];
		lazy[i] = i;
	}

	MST(1, v);
	MST(Q, v);
	bs(1, Q, v);

	ll sumL = 0, sumR = 0;
	int pivot = 0;
	for(int i = 1; i <= Q; i++)
	{
		if(!mst[i].empty())
		{
			pivot = sumL = sumR = 0;	
			for(int j = 0; j < mst[lazy[i]].size(); j++)
				if(w[mst[i][j]] <= q[i])
					pivot = j + 1, sumL += w[mst[i][j]];
				else
					sumR += w[mst[i][j]];
		}
		if(!lazy[i])
		   lazy[i] = lazy[i - 1];	
		while(pivot < mst[lazy[i]].size() && w[mst[lazy[i]][pivot]] <= q[i])
		{
			sumL += w[mst[lazy[i]][pivot]];
			sumR -= w[mst[lazy[i]][pivot]];
			pivot++;
		}
		cout << pivot * q[i] - sumL + sumR - (mst[lazy[i]].size() - pivot) * q[i] << '\n';
	}
}	
