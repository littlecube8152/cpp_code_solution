#include "minerals.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int pre, cur;

bool change(int x)
{
	// cerr << "change " << x << '\n';
	cur = Query(x);
	swap(pre, cur);
	return pre != cur;
}

double multi = 0.4;


void solve(vector<int> X, vector<int> Y, bool bX, bool bY)
{	
	if(X.size() == 1)
	{
		Answer(X[0], Y[0]);
		return;
	}
	int N = X.size(), mid = (N >= 10 ? floor(multi * N) : N / 2);

	vector<int> lX(X.begin(), X.begin() + mid), rX(X.begin() + mid, X.end()), lY, rY;

	if(bX)
		for(int i = 0; i < mid; i++)
			change(X[i]);
	else
		for(int i = 0; i < mid; i++)
			change(X[i]);

	for(int i : Y)
	{		
		if(change(i) ^ bX)
			rY.emplace_back(i);
		else 
			lY.emplace_back(i);
		if(lY.size() == mid || rY.size() == N - mid)
			break;
	}
	if(lY.size() == mid)
		while(rY.size() < N - mid)
		{
			rY.emplace_back(Y.back());
			Y.pop_back();
		}
	else
		while(lY.size() < mid)
		{
			lY.emplace_back(Y.back());
			Y.pop_back();
		}

	solve(lX, lY, !bX, !bY);
	solve(rX, rY, bX, !bY);

}

void Solve(int N)
{
	//cin >> multi;
	pre = cur = 0;
	vector<int> X, Y;

	//mt19937 rd(std::chrono::steady_clock::now().time_since_epoch().count());

	for(int i = 1; i <= 2 * N; i++)
	{
		if(change(i))
			X.emplace_back(i);
		else
			Y.emplace_back(i);
	}
	//shuffle(X.begin(), X.end(), rd);
	//shuffle(Y.begin(), Y.end(), rd);
	solve(X, Y, 1, 1);
}
