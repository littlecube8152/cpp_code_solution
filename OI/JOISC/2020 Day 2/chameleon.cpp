#include "chameleon.h"
#include <iostream>
#include <vector>
using namespace std;


vector<int> A, B, E[1005];
int color[1005], q;
vector<int> adj;

vector<int> with(int u, vector<int> v)
{
	v.emplace_back(u);
	return v;
}

void find(int u, vector<int> v)
{	
	if(v.empty())
		return;
	if(v.size() == 1)
		adj.emplace_back(v[0]);
	else
	{
		int mid = v.size() / 2;
		vector<int> l(v.begin(), v.begin() + mid), r(v.begin() + mid, v.end());
		if(Query(with(u, l)) <= l.size())
			find(u, l);
		else 
			find(u, r);
	}
}


vector<int> erase(vector<int> v, int u)
{
	bool flag = 0;
	for(int i = 0; i < v.size(); i++)
	{
		if(flag)
			v[i - 1] = v[i];
		if(v[i] == u)
			flag = 1;
	}
	if(flag)
		v.pop_back();
	return v;
}

void dfs(int u)
{
	for (auto v : E[u])
		if(!color[v])
		{
			color[v] = 3 ^ color[u];
			dfs(v);
		}
}

void Solve(int N)
{
	for (int i = 1; i <= 2 * N; i++)
	{
		for (int j = 1; j < i; j++)
			color[j] = 0;
		for (int j = 1; j < i; j++)
			if(!color[j])
			{
				color[j] = 1;
				dfs(j);
			}
		A.clear(), B.clear();
		for (int j = 1; j < i; j++)
			(color[j] == 1 ? A : B).emplace_back(j);
		adj.clear();
		while(Query(with(i, A)) <= A.size())
		{
			find(i, A);
			A = erase(A, adj.back());
		}
		while(Query(with(i, B)) <= B.size())
		{
			find(i, B);
			B = erase(B, adj.back());
		}
		for (int j : adj)
		{
			E[i].emplace_back(j);
			E[j].emplace_back(i);
		}
	}
	for (int i = 1; i <= 2 * N; i++)
		if(E[i].size() == 3)
		{
			int a = E[i][0], b = E[i][1], c = E[i][2];
			int x = Query(vector<int>{i, a, b}),
				y = Query(vector<int>{i, b, c}),
				z = 5 - x - y;
			if(x == 2 && y == 2)
				E[i].emplace_back(-b), E[b].emplace_back(-i);
			else if(y == 2 && z == 2)
				E[i].emplace_back(-c), E[c].emplace_back(-i);
			else if(z == 2 && x == 2)	
				E[i].emplace_back(-a), E[a].emplace_back(-i);
		}
		else if(E[i].size() == 4)
		{
			int a = E[i][0], b = E[i][1], c = E[i][2];
			int x;
			if(E[i][3] == -a)
				x = (Query(vector<int>{i, a, b}) == 2 ? b : c);
			else if(E[i][3] == -b)
				x = (Query(vector<int>{i, b, c}) == 2 ? c : a);
			else	
				x = (Query(vector<int>{i, c, a}) == 2 ? a : b);
					
			E[i].emplace_back(-x), E[x].emplace_back(-i);
		}
	for (int i = 1; i <= 2 * N; i++)
	{
		int sum = 0;
		for(auto j : E[i])
			sum += j;
		if(i < sum)
			Answer(i, sum);
	}

}
