#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, Q, ans[300005], state[300005];
map<pii, int> mp;
vector<pair<pii, int>> in[300005], out[300005];
vector<pii> qu[300005];

void insert(int p, int t)
{
	auto rter = mp.upper_bound(pii(p, 0));
	auto lter = prev(rter);
	int l = p, r = p;
	if(rter != mp.end() && rter->F.F == p + 1)
	{
		auto [a, b] = rter->F;
	   	int s = rter->S;
		in[a].emplace_back(make_pair(pii(s, t), a));
		out[b].emplace_back(make_pair(pii(s, t), a));
		r = b;
		mp.erase(rter);
	}
	if(lter->F.S == p - 1)
	{
		auto [a, b] = lter->F; 
	   	int s = lter->S;
		in[a].emplace_back(make_pair(pii(s, t), a));
		out[b].emplace_back(make_pair(pii(s, t), a));
		l = a;
		mp.erase(lter);
	}
	mp[pii(l, r)] = t + 1;
}

void erase(int p, int t)
{
	auto iter = prev(mp.lower_bound(pii(p, N + 1)));
	auto [a, b] = iter->F;
    int s = iter->S;
	in[a].emplace_back(make_pair(pii(s, t), a));
	out[b].emplace_back(make_pair(pii(s, t), a));
	mp.erase(iter);
	if(a < p)
		mp[pii(a, p - 1)] = t + 1;
	if(p < b)
		mp[pii(p + 1, b)] = t + 1;
}

struct segTree
{
	vector<int> seg, l, r, lazy;
	vector<int> pos;
	int sz;
	inline int newnode()
	{
		seg.emplace_back(0);
		l.emplace_back(0);
		r.emplace_back(0);
		lazy.emplace_back(0);
		return (int)seg.size() - 1;
	}
	inline void apply(int val, int i, int L, int R)
	{
		lazy[i] += val;
		seg[i] += val * (pos[R] - pos[L]);
	}	
	void modify(int mL, int mR, int val, int i = 0, int L = 0, int R = - 1)
	{
		if(R == -1)
			R += sz;
		if(mL <= pos[L] && pos[R] <= mR)
			apply(val, i, L, R);
		else if(pos[R] <= mL || mR <= pos[L])
			return;
		else
		{
			int mid = (L + R) / 2;
			if(!l[i]) l[i] = newnode();
			if(!r[i]) r[i] = newnode();
			apply(lazy[i], l[i], L, mid);
			apply(lazy[i], r[i], mid, R);
			lazy[i] = 0;
			modify(mL, mR, val, l[i], L, mid);
			modify(mL, mR, val, r[i], mid, R);
			seg[i] = seg[l[i]] + seg[r[i]];
		}
	}
	int query(int mL, int mR, int i = 0, int L = 0, int R = -1)
	{
		if(R == -1)
			R += sz;
		if(mL <= pos[L] && pos[R] <= mR)
			return seg[i];
		else if(pos[R] <= mL || mR <= pos[L])
			return 0;
		else
		{
			int mid = (L + R) / 2;
			if(!l[i]) l[i] = newnode();
			if(!r[i]) r[i] = newnode();
			apply(lazy[i], l[i], L, mid);
			apply(lazy[i], r[i], mid, R);
			lazy[i] = 0;
			return query(mL, mR, l[i], L, mid) + query(mL, mR, r[i], mid, R);
		}
	}

} tree[300005];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	mp[pii(-2, -2)] = -1;
	cin >> N >> Q;
	for(int i = 1; i <= N; i++)
	{
		char c;
		cin >> c;
		state[i] = c - '0';
	}
	for (int i = 1; i <= N; i++)
		if(state[i])
		{
			int j = i;
			while(state[j + 1])
				j++;
			mp[pii(i, j)] = 1;
			i = j;
		}	
	for (int i = 1; i <= Q; i++)
	{
		string s;
		int a, b;
		cin >> s;
		if(s == "toggle")
		{
			ans[i] = -1;
			cin >> a;
			state[a] ^= 1;
			if(state[a])
				insert(a, i);
			else 
				erase(a, i);
		}
		else if(s == "query")
		{
			cin >> a >> b;
			b--;
			qu[b].emplace_back(pii(a, i));
		}
		//for (auto [p, v] : mp)
		//	cerr << "(" << p.F << ", " << p.S << ") " << v << "  ";
		//cerr << '\n';
	}
	mp.erase(mp.begin());
	for (auto [p, v] : mp)
	{
		auto [a, b] = p;
		in[a].emplace_back(make_pair(pii(v, Q), a));
		out[b].emplace_back(make_pair(pii(v, Q), a));
	}

	
	for (int i = 1; i <= N; i++)
	{
		for (auto [p, k] : in[i])
		{
			auto [l, r] = p;
			//cerr << l << ' ' << r << ' ' << k << ' ' << i << '\n';
			for (; k <= N; k += (k & -k))
				tree[k].pos.emplace_back(l), tree[k].pos.emplace_back(r + 1);
		}

		for (auto [r, j] : qu[i])
		{
			for (; r > 0; r -= (r & -r))
				tree[r].pos.emplace_back(j + 1);
		}
	}

	for (int i = 1; i <= N; i++)
	{	
		tree[i].newnode();
		sort(tree[i].pos.begin(), tree[i].pos.end());
		tree[i].pos.resize(unique(tree[i].pos.begin(), tree[i].pos.end()) - tree[i].pos.begin());
		tree[i].sz = tree[i].pos.size();
	}

	for (int i = 1; i <= N; i++)
	{
		for (auto [p, k] : in[i])
		{
			auto [l, r] = p;
			//cerr << l << ' ' << r << ' ' << k << ' ' << i << '\n';
			for (; k <= N; k += (k & -k))
				tree[k].modify(l, r + 1, 1);
		}
		
		for (auto [r, j] : qu[i])
		{
			for (; r > 0; r -= (r & -r))
				ans[j] += tree[r].query(0, j + 1);
		}

		for (auto [p, k] : out[i])
		{
			auto [l, r] = p;
			//cerr << l << ' ' << r << ' ' << k << ' ' << i <<  " out " << '\n';
			for (; k <= N; k += (k & -k))
				tree[k].modify(l, r + 1, -1);

		}


	}
	for (int i = 1; i <= Q; i++)
		if(ans[i] >= 0)
			cout << ans[i] << '\n';
}
