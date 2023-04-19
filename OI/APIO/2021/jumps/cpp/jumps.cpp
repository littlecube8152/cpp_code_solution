#include "jumps.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;


namespace 
{
	const int P = 20;
	int N, H[200005], strong[200005][P], weak[200005][P];
   	pii st[200005][P];
	
	pii query(int l, int r)
	{
		if(r < l) return pii(0, 0);
		int lg = __lg(r - l + 1);
	   	return max(st[l][lg], st[r - (1 << lg) + 1][lg]);	
	}
}


void init(int N, std::vector<int> h)
{
	::N = N;
	for(int i = 1; i <= N; i++)
		st[i][0] = pii(H[i] = h[i - 1], i);
	for(int p = 0; p + 1 < P; p++)
		for(int i = 1; i <= N; i++)
			st[i][p + 1] = max(st[i][p], st[i + (1 << p)][p]);
	H[0] = H[N + 1] = 1e9 + 10;
	vector<int> v = vector<int>{0};
	for (int i = 1; i <= N; i++)
	{
		while(!v.empty() && H[v.back()] <= H[i])
			v.pop_back();
		strong[i][0] = v.back();
		v.emplace_back(i);
	}
	v = vector<int>{N + 1};
	
	for(int i = N; i >= 1; i--)
	{
		while(!v.empty() && H[v.back()] <= H[i])
			v.pop_back();
		weak[i][0] = v.back();
		if(H[weak[i][0]] > H[strong[i][0]])
			swap(weak[i][0], strong[i][0]);
		v.emplace_back(i);
	}
	for(int i = 1; i < P; i++)
		strong[i][P] = strong[strong[i][P - 1]][P - 1], weak[i][P] = weak[weak[i][P - 1]][P - 1];
	
}

int minimum_jumps(int A, int B, int C, int D)
{
	A++, B++, C++, D++;
}
