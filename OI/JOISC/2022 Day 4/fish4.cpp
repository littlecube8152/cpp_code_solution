#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, Q;
ll A[100005], bit[100005], ans[100005], res[100005], invalid[100005], sum[100005], child[100005][2], pre[100005][2], root, range[100005][2], table[18][100005];
pii query[100005];
vector<int> qb[100005];
map<int, int> vir[2];

void Modify(int pos, int val)
{
	for(int i = pos; i <= N; i += (i & -i))
		bit[i] += val;
}

int Query(int pos)
{
	int a = 0;
	for(int i = pos; i > 0; i -= (i & -i))
		a += bit[i];
	return a;
}

void invalidate(int u, int dir)
{
	if(invalid[u]) return;

	if(sum[u] < A[pre[u][dir ^ 1]] || !res[pre[u][dir ^ 1]])
	{	
		Modify(u, -res[u]);
		res[u] = 0, invalid[u] = 1;
		if(child[u][0])
			invalidate(child[u][0], 0);
		if(child[u][1])
			invalidate(child[u][1], 1);

	}
}

void dfs(int u, int dir)
{
	if(child[u][0])
		dfs(child[u][0], 0);
	if(child[u][1])
		dfs(child[u][1], 1);
	sum[u] = A[u] + sum[child[u][0]] + sum[child[u][1]];

	range[u][0] = (child[u][0] ? range[child[u][0]][0] : u);
	range[u][1] = (child[u][1] ? range[child[u][1]][1] : u);

	res[u] = 1;
	Modify(u, 1);
	
	if(child[u][0])
		invalidate(child[u][0], 0);
	if(child[u][1])
		invalidate(child[u][1], 1);
	
	for(int i : qb[u])
	{
		auto [l, r] = query[i];
		cout << u << ' ' << l << ' ' << r << '\n';
		auto iter = vir[0].upper_bound(r);
		if(iter != vir[0].end() && iter->S > 0)
			r = range[iter->S][0] - 1;
		
		iter = vir[1].upper_bound(l);
		if(iter != vir[1].end() && iter->S > 0)
			l = range[iter->S][1] + 1;
		ans[i] = Query(r) - Query(l - 1);
	}

	if(dir != 2)
		if(pre[u][dir] && sum[u] < A[pre[u][dir]])
		{
			int l = u, r = pre[u][dir ^ 1];
			auto iter = vir[dir].lower_bound(l);
			while(iter != vir[dir].end() && iter->S <= r)
				iter = vir[dir].erase(iter);
			vir[dir][l] = (dir == 0 ? -1 : 1) * u;
			vir[dir][r] = (dir == 0 ? 1 : -1) *  u;
		}
}




signed main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0), cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> A[i];
	
	vector<int> v;
	for(int i = 1; i <= N; i++)
	{
		while(!v.empty() && A[v.back()] < A[i])
		{	
			pre[v.back()][1] = i;
			v.pop_back();
		}
		v.push_back(i);
	}
	v.clear();
	for(int i = N; i >= 1; i--)
	{
		while(!v.empty() && A[v.back()] <= A[i])
		{	
			pre[v.back()][0] = i;
			v.pop_back();
		}
		v.push_back(i);
	}
	v.clear();

	for(int i = 1; i <= N; i++)
		if(!child[pre[i][1]][0])
			child[pre[i][1]][0] = i;
	
	for(int i = N; i >= 1; i--)
		if(!child[pre[i][0]][1])
			child[pre[i][0]][1] = i;
	
	for(int i = 1; i <= N; i++)
		if(pre[i][0] == 0 && pre[i][1] == 0)
			root = i;
	
	for(int i = 1; i <= N; i++)
		table[0][i] = i;

	for(int p = 1; p <= 17; p++)
		for(int i = 1; i <= N; i++)
		{
			int res = (A[i] >= A[min(N, i + (1 << (p - 1)))] ? i : min(N, i + (1 << (p - 1))));
			table[p][i] = res;
		}

	cin >> Q;
	for(int i = 1; i <= Q; i++)
	{
		int T, X, Y;
		cin >> T >> X >> Y;
		assert(T == 2);
		int p = __lg(Y - X + 1);
		int idx = (A[table[p][X]] >= A[table[p][Y - (1 << p) + 1]] ? table[p][X] : table[p][Y - (1 << p) + 1]);
		qb[idx].emplace_back(i);
		query[i] = pii(X, Y);
	}

	dfs(root, 2);

	for(int i = 1; i <= Q; i++)
		cout << ans[i] << '\n';
}
