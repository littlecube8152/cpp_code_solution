#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, m;
ll a[20], b[20], s[1 << 20];
vector<ll> l, r;

void sos(int k)
{
	for (int i = 0; i < (1 << k); i++)
		for (int j = 0; j < k; j++)
			if (i & (1 << j))
				s[i] &= s[i ^ (1 << j)];
}	

void proc(int k, ll* e, vector<ll> &v)
{
	for (int i = 0; i < (1 << k); i++)
	{	
		s[i] = 0;
		for (int j = 0; j < k; j++)	
			if (i & (1 << j))
				s[i] |= e[j];
		if (__builtin_popcount(s[i]) >= __builtin_popcount(i))
			 s[i] = 1;
		else s[i] = 0;
	}
	sos(k);
	for (int i = 0; i < k; i++)
		cin >> e[i];
	for (int i = 0; i < (1 << k); i++)
	{	
		ll sum = 0;
		for (int j = 0; j < k; j++)	
			if (i & (1 << j))
				sum += e[j];
		if (s[i])
			v.emplace_back(sum);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == '0')
				continue;			
			a[i] |= (1 << j);
			b[j] |= (1 << i);
		}
	proc(n, a, l);
	proc(m, b, r);
	sort(l.begin(), l.end());
	sort(r.begin(), r.end(), greater<>());
	ll t, ans = 0;
	cin >> t;
	for (int i = 0, j = 0; i < l.size(); i++)
	{
		while (j < r.size() && r[j] + l[i] >= t)
			j++;
		ans += j;
	}
	cout << ans << '\n';
}
