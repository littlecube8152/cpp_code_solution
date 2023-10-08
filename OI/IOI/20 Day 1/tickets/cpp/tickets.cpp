#include "tickets.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define ll long long
using namespace std;

int pcnt[1500];
vector<int> pos[1500], neg[1500];

ll find_maximum(int k, vector<vector<int>> x)
{
	int n = x.size();
	int m = x[0].size();
	vector<vector<pii>> a;
	vector<vector<int>> answer;
	a.resize(n), answer.resize(n);
	priority_queue<pii> pq;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			ans -= x[i][j];
		pq.push(pii(x[i][m - 1] + x[i][k - 1], i));
	}
	for (int t = 1; t <= n / 2 * k; t++)
	{
		auto [val, i] = pq.top();
		pq.pop();
		ans += val;
		pcnt[i]++;
		if (pcnt[i] < k)
			pq.push(pii(x[i][m - 1 - pcnt[i]] + x[i][k - 1 - pcnt[i]], i));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k - pcnt[i]; j++)
			neg[i].emplace_back(j);
		for (int j = 0; j < pcnt[i]; j++)
			pos[i].emplace_back(m - j - 1);
	}
	for (int i = 0; i < n; i++)
		answer[i].resize(m, -1);

	for (int i = 0; i < k; i++)
	{
		vector<int> vis(n, 0);
		int l = n / 2, r = n / 2;
		for (int j = 0; j < n; j++)
			if (pos[j].empty())
			{
				r--;
				answer[j][neg[j].back()] = i;
				neg[j].pop_back();
				vis[j] = 1;
			}
			else if (neg[j].empty())
			{
				l--;
				answer[j][pos[j].back()] = i;
				pos[j].pop_back();
				vis[j] = 1;
			}
		for (int j = 0; j < n; j++)
			if (!vis[j])
			{
				if (l)
				{
					l--;
					answer[j][pos[j].back()] = i;
					pos[j].pop_back();
				}
				else
				{
					r--;
					answer[j][neg[j].back()] = i;
					neg[j].pop_back();
				}
			}
	}
	allocate_tickets(answer);
	return ans;
}