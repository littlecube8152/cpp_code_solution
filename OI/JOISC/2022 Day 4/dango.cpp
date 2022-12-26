#include "dango3.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int Query(vector<int> v, vector<int> u)
{
	for(int i : u)
		v.emplace_back(i);
	return Query(v);
}

void Solve(int N, int M)
{
	cerr << N << ' ' << M << '\n';
	mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
	vector<int> v;
	for(int i = 1; i <= N * M; i++)
		v.emplace_back(i);
	shuffle(v.begin(), v.end(), rd);
	for(int i = M - 1; i > 0; i--)
	{
		shuffle(v.begin(), v.end(), rd);
		vector<int> ign, ans;
		ans.emplace_back(v.back());
		v.pop_back();
		while(ans.size() < N)
		{
			int k = v.back();
			v.pop_back();
			if(Query(v, ign) == i)
				ans.emplace_back(k);
			else 
				ign.emplace_back(k);
		}
		for(int i : ign)
			v.emplace_back(i);
		Answer(ans);
	}
	Answer(v);
}
