
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int a, 

void init()
{
	for(int i = 1; i <= N; i++)
		bit[i] = -1e10;
}

void modify(int pos, ll val)
{
	for(int i = pos; i <= N; i += (i & -i))
		bit[i] = max(bit[i], val);
}

ll query(int pos)
{
	ll ans = -1e10;
	for(int i = pos; i > 0; i -= (i & -i))
		ans = max(ans, bit[i]);
	return ans;
}

int ypos[150005];

signed main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> a[i].x >> a[i].y >> a[i].z;
	sort(a + 1, a + 1 + N, [&](ppl p, ppl q){ return make_tuple(p.x, p.y, p.z) < make_tuple(q.x, q.y, q.z); });

	N = unique(a + 1, a + 1 + N, [&](ppl p, ppl q){ return make_tuple(p.x, p.y, p.z) == make_tuple(q.x, q.y, q.z); }) - a - 1;
	


	int t = 2;
	while(t--)
	{	
		vector<int> v;
		for(int i = 1; i <= N; i++)
			v.emplace_back(a[i].y);
		sort(v.begin(), v.end());
		for(int i = 1; i <= N; i++)
			ypos[i] = lower_bound(v.begin(), v.end(), a[i].y) - v.begin() + 1;
		init();

		for(int i = 1, nxt = 1; i <= N; i++)
		{	
			while(a[nxt].x < a[i].x)
			{
				modify(ypos[nxt], a[nxt].z);
				nxt++;
			}

			for(int j = 1; a[j].x < a[i].x; j++)
			{
				if(a[j].y <= a[i].y)
					continue;
				ll mxz = query(ypos[j] - 1);
				if(mxz > max(a[j].z, a[i].z))
					ans = max(ans, a[i].x + a[j].y + mxz);
			}
		}
		for(int i = 1; i <= N; i++)
			swap(a[i].y, a[i].z);
	}
	cout << ans << '\n';
}
