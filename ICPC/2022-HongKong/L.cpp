#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

int T, N, M, K, a[200005], b[200005], stay[200005], pos[200005], bit[200005];

void modify(int pos)
{
	for (; pos <= N; pos += (pos & -pos))
		bit[pos]++;
}

int query(int pos)
{
	int ans = 0;
	for (; pos; pos -= (pos & -pos))
		ans += bit[pos];
	return ans;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N >> M >> K;
		for (int i = 1; i <= N; i++)
			cin >> a[i], pos[a[i]] = i;
		for (int i = 1; i <= M; i++)
			cin >> b[i];

		fill(stay + 1, stay + 1 + N, 0);
		fill(bit + 1, bit + 1 + N, 0);
		b[M + 1] = 0;
		int j = 1;
		for (int i = 1; i <= N; i++)
		{
			if (a[i] == b[j])
				stay[a[i]] = 1, j++;
		}
		
		bool flag = (j == M + 1);
		multiset<int, greater<int>> ms; 
		for (int i = 1; i <= K; i++)
		{
			int l;
			cin >> l;
			ms.insert(l);
		}

		set<pii> st;
		st.insert(pii(1, N));
		for (int i = N; i >= 1; i--)
		{
			auto iter = prev(st.lower_bound(pii(pos[i], N + 1)));
			if (stay[i])
			{
				if (iter->F <= pos[i] - 1)
					st.insert(pii(iter->F, pos[i] - 1));
				if (pos[i] + 1 <= iter->S)
					st.insert(pii(pos[i] + 1, iter->S));
				st.erase(iter);
			}
			else 
			{
				int l = iter->S - iter->F + 1 - (query(iter->S) - query(iter->F - 1));
			   	auto jter = ms.lower_bound(l);
				if (jter == ms.end())
					flag = 0;
				else 
					ms.erase(jter);	
				modify(pos[i]);
			}
		}
		cout << (flag ? "YES\n" : "NO\n");
	}
}




