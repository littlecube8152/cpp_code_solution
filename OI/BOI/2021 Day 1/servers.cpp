#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, K, a[240005], b[240005], dsu[120005], rk[120005], aca[240005], acb[240005], ans[240005], cur[120005];
vector<int> Q[120005];
map<int, int> mp[240005];
vector<pii> undo;
char t[240005];

int find(int k)
{
	return dsu[k] == k ? k : find(dsu[k]);
}

void merge(int x, int y, int tag = 0)
{
	int rx = find(x), ry = find(y);
	if(rx == ry)
		return;
	if(rk[rx] <= rk[ry])
	{
		dsu[rx] = ry;
		rk[ry] += rk[rx];
		if(tag)
		{	
			Q[ry].emplace_back(tag);
			aca[tag] = rx;
			acb[tag] = ry;
		}
		else 
			undo.emplace_back(pii(rx, ry));
	}
	else
	{
		dsu[ry] = rx;
		rk[rx] += rk[ry];
		if(tag)
		{	
			Q[rx].emplace_back(tag);
			aca[tag] = rx;
			acb[tag] = ry;
		}
		else 
			undo.emplace_back(pii(ry, rx));

	}
}

void rollback(int t)
{
	while(undo.size() > t)
	{
		auto [x, y] = undo.back();
		undo.pop_back();
		dsu[x] = x;
		rk[y] -= rk[x];
	}
}

void solve(int k)
{
	int sz = undo.size();
	while(!Q[k].empty())
	{
		int i = Q[k].back();
		Q[k].pop_back();
		if(t[i] == 'S')
		{
			merge(a[i], b[i]);
			solve(aca[i]);
			solve(acb[i]);
			break;	
		}
		else if(t[i] == 'Q')
			ans[i] = (find(a[i]) == find(b[i]));
	}
	rollback(sz);
}

signed main()
{
	cin >> N >> K;
	K += N - 1;
	for(int i = 1; i <= K; i++)
	{
		cin >> t[i];
		if(t[i] == 'C')
			cin >> a[i];
		else
			cin >> a[i] >> b[i];
	}	
	for(int i = 1; i <= N; i++)
		dsu[i] = i, cur[i] = rk[i] = 1;
	for(int i = K; i >= 1; i--)
	{
		if(t[i] == 'S')
		{	
			merge(a[i], b[i], i);
			cur[a[i]] += cur[b[i]];
			cur[b[i]] = cur[a[i]];
		}
		else if(t[i] == 'C')
			ans[i] = cur[a[i]];
		else
		{
			int r = find(a[i]);
			Q[r].emplace_back(i);
		}
	}
	int r = find(1);
	for(int i = 1; i <= N; i++)
		dsu[i] = i, rk[i] = 1;
	solve(r);
	for(int i = 1; i <= K; i++)
		if(t[i] == 'C')
			cout << ans[i] << '\n';
		else if(t[i] == 'Q')
			cout << (ans[i] ? "yes\n" : "no\n");
}
