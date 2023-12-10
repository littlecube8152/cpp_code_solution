#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define piiii tuple<bigInt, int, int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;


const static int base = 1'000'000'000'000'000'000;

struct bigInt
{
	vector<int> val;
};

bigInt operator+(bigInt i, bigInt j)
{
	vector<int> u = i.val, v = j.val;
	int k = max(u.size(), v.size());
	u.resize(k + 1, 0), v.resize(k + 1, 0);
	for (int i = 0; i < k; i++)
		u[i + 1] += (u[i] + v[i]) / base, u[i] = (u[i] + v[i]) % base;
	if (u.back() == 0)
		u.pop_back();
	return bigInt{u};
}

bool operator<(bigInt i, bigInt j)
{
	vector<int> u = i.val, v = j.val;
	reverse(all(u));
	reverse(all(v));
	return u.size() < v.size() || (u.size() == v.size() && u < v);
}


int n, m, s, t, p;
bigInt dp[30][30][30];
bool notinf[30][30][30];
int can[30][30];
vector<pii> g[30];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> p;
	for (int i = 1; i <= p; i++)
	{
		string a, b, c;
		cin >> a >> b >> c;
		if (c.size() == 2)
			g[a[0] - 'A'].emplace_back(c[0] - 'A', c[1] - 'A');
		else 
			can[a[0] - 'A'][c[0] - 'a'] = 1;
	}
	
	cin >> n >> m >> s >> t;
	
	priority_queue<piiii, vector<piiii>, greater<piiii>> pq;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		char c; 
		cin >> a >> b >> c;
		for (int j = 0; j < 26; j++)
			if (can[j][c - 'a'])
			{	
				dp[a][b][j] = bigInt{{1}};
				pq.push(piiii(dp[a][b][j], a, b, j));
				notinf[a][b][j] = 1;
			}
		
	}
		
	while(!pq.empty())
	{
		auto [d, i, j, c] = pq.top();
		pq.pop();
		if (dp[i][j][c] < d) continue;	
		for (int b = 0; b < 26; b++)
			for (auto [x, y] : g[b])				
			{	
				if (x == c)
				{
					for (int k = 1; k <= n; k++)
						if (!notinf[j][k][y]);
						else if (!notinf[i][k][b] || dp[i][j][x] + dp[j][k][y] < dp[i][k][b])
						{
							dp[i][k][b] = dp[i][j][x] + dp[j][k][y];
							notinf[i][k][b] = 1;
							pq.push(piiii(dp[i][k][b], i, k, b));
						}
				}
				if (y == c)
				{
					for (int k = 1; k <= n; k++)
						if (!notinf[k][i][x]);
						else if (!notinf[k][j][b] || dp[k][i][x] + dp[i][j][y] < dp[k][j][b])
						{
							dp[k][j][b] = dp[k][i][x] + dp[i][j][y];
							notinf[k][j][b] = 1;
							pq.push(piiii(dp[k][j][b], k, j, b));
						}			
	
				}
			}
	}

	if (!notinf[s][t]['S' - 'A'])
		cout << "NO\n";
	else
	{
		vector<int> ans = dp[s][t]['S' - 'A'].val;
		cout << ans.back();
		ans.pop_back();
		while (!ans.empty())
			cout << setfill('0') << setw(18) << ans.back(), ans.pop_back();
	}
}

