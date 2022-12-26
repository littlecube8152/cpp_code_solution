#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, dsu[100005], rk[100005];
ll ans;
set<int> fd[100005], f[100005], fdr[100005], fr[100005];

vector<pii> chain;

int find(int k)
{
	return k == dsu[k] ? k : dsu[k] = find(dsu[k]);
}

void Merge(set<int> &small, set<int> &big)
{
	for (int i : small)
		big.insert(i);
}

void query(set<int> &small, set<int> &big, int another)
{
	for (int i : small)
		if (big.find(i) != big.end())
			chain.emplace_back(pii(i, another));
}

void follow(int a, int b)
{
	// cout << "merge " << a << " " << b << '\n';
	// out A <-> in B
	if (fr[a].size() <= fdr[b].size())
		query(fr[a], fdr[b], a);
	else
		query(fdr[b], fr[a], a);

	if (fr[b].size() <= fdr[a].size())
		query(fr[b], fdr[a], a);
	else
		query(fdr[a], fr[b], a);

	if (rk[a] <= rk[b])
		for (int i : fdr[a])
		{
			fr[i].erase(a);
			fr[i].insert(b);
		}
	else
		for (int i : fdr[b])
		{
			fr[i].erase(b);
			fr[i].insert(a);
		}

	if (rk[a] <= rk[b])
		for (int i : fr[a])
		{
			fdr[i].erase(a);
			fdr[i].insert(b);
		}
	else
		for (int i : fr[b])
		{
			fdr[i].erase(b);
			fdr[i].insert(a);
		}
	// cout << fd[a].size() << " " << fd[b].size() << " ";
	ans -= fd[a].size() * rk[a] + fd[b].size() * rk[b];

	if (fd[a].size() <= fd[b].size())
		Merge(fd[a], fd[b]);
	else
		Merge(fd[b], fd[a]);

	if (fdr[a].size() <= fdr[b].size())
		Merge(fdr[a], fdr[b]);
	else
		Merge(fdr[b], fdr[a]);

	if (f[a].size() <= f[b].size())
		Merge(f[a], f[b]);
	else
		Merge(f[b], f[a]);

	if (fr[a].size() <= fr[b].size())
		Merge(fr[a], fr[b]);
	else
		Merge(fr[b], fr[a]);
	// cout << max(fd[a].size(), fd[b].size()) << '\n';
	ans += max(fd[a].size(), fd[b].size()) * (rk[a] + rk[b]);
	// cout << "update ans " << ans << '\n';
	if (rk[a] <= rk[b])
	{
		dsu[a] = b;
		rk[b] += rk[a];

		if (f[a].size() >= f[b].size())
			f[a].swap(f[b]);
		if (fd[a].size() >= fd[b].size())
			fd[b].swap(fd[a]);
		if (fr[a].size() >= fr[b].size())
			fr[a].swap(fr[b]);
		if (fdr[a].size() >= fdr[b].size())
			fdr[b].swap(fdr[a]);
	}
	else
	{
		dsu[b] = a;
		rk[a] += rk[b];
		fd[a].swap(fd[b]);
		if (f[a].size() <= f[b].size())
			f[a].swap(f[b]);
		if (fd[a].size() <= fd[b].size())
			fd[b].swap(fd[a]);
		if (fr[a].size() <= fr[b].size())
			fr[a].swap(fr[b]);
		if (fdr[a].size() <= fdr[b].size())
			fdr[b].swap(fdr[a]);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), // cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		dsu[i] = i, rk[i] = 1;
		fd[i].insert(i);
		f[i].insert(i);
		fdr[i].insert(i);
		fr[i].insert(i);
	}
	for (int i = 1; i <= M; i++)
	{
		int A, B;
		cin >> A >> B;
		if (find(A) == find(B))
			;
		else if (fd[find(B)].find(A) != fd[find(B)].end())
			;
		else if (fd[find(A)].find(B) != fd[find(A)].end())
		{
			// // cout << "mergeeee\n";
			chain.emplace_back(pii(A, B));
		}
		else
		{
			// // cout << "simple follow\n";
			if (fr[find(B)].find(find(A)) != fr[find(B)].end())
				chain.emplace_back(pii(A, B));

			fd[find(B)].insert(A);
			f[find(A)].insert(B);
			fdr[find(B)].insert(find(A));
			fr[find(A)].insert(find(B));
			ans += rk[find(B)];
		}
		while (!chain.empty())
		{
			auto [a, b] = chain.back();
			chain.pop_back();
			if (find(a) != find(b))
				follow(find(a), find(b));
		}

		cout << ans << '\n';
	}
}
