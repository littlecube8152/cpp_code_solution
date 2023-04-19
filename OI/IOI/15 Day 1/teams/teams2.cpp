#include "teams.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

vector<pair<pii, int>> u, v;
int N, p[500005], s[500005];

void init(int n, int A[], int B[])
{
	N = n;
	for (int i = 0; i < N; i++)
	{
		u.emplace_back(make_pair(pii(A[i], B[i]), 1));
		p[A[i]]++;
		s[B[i]]++;
	}
	for (int i = 1; i <= N; i++)
		s[i] += s[i - 1];
	for (int i = N; i >= 0; i--)
		p[i] += p[i + 1];
}

const int B = 500;

int query(int L, int R)
{
	cout << " q " << L << ' ' << R << " " << N - p[L + 1] - s[R - 1] + (N - s[L - 1] - p[R + 1]) << '\n';
	return N - p[L + 1] - s[R - 1] + (N - s[L - 1] - p[R + 1]);
}

int can(int M, int K[])
{

	priority_queue<pii, vector<pii>, greater<pii>> pq;

	if (M > B)
		v = u;
	else
	{
		vector<int> val;
		for (int i = 0; i < M; i++)
			val.emplace_back(K[i]);
		sort(val.begin(), val.end());
		val.resize(unique(val.begin(), val.end()) - val.begin());
		int Q = val.size();
		for (int i = 0; i < Q; i++)
			for (int j = i; j < Q; j++)
			{
				int cnt = query(val[i], val[j]);
				if (i > 0)
					cnt -= query(val[i - 1], val[j]);
				if (j + 1 < Q)
					cnt -= query(val[i], val[j + 1]);
				if (i > 0 && j + 1 < Q)
					cnt = cnt + query(val[i - 1], val[j + 1]);
				v.emplace_back(make_pair(pii(val[i], val[j]), cnt));
				cerr << val[i] << ' ' << val[j] << " = " << cnt << '\n';
			}
	}
	for (int i = 0; i < M; i++)
		v.emplace_back(make_pair(pii(K[i], 1e9), 0));

	sort(v.begin(), v.end());
	for (auto [p, cnt] : v)
	{
		auto [L, R] = p;
		if (R >= 1e8)
		{
			while (!pq.empty() && pq.top().F < L)
				pq.pop();
			while (!pq.empty() && L > 0)
			{
				auto [val, rem] = pq.top();
				pq.pop();
				if (L >= rem)
					L -= rem;
				else
				{
					pq.push(pii(val, rem - L));
					L = 0;
				}
			}
			if (L)
				return 0;
		}
		else
			pq.push(pii(R, cnt));
	}
	return 1;
}
