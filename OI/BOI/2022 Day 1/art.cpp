#include "art.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int vis[4005], arr[4005];

void solve(int N)
{
	vector<int> ans(N);
	vector<int> v;
	for (int i = 1; i <= N; i++)
		v.emplace_back(i);
	for (int i = 1; i <= N; i++)
	{
		arr[i] = publish(v);
		v.erase(v.begin());
		v.emplace_back(i);
	}
	arr[N + 1] = arr[1];
	for (int i = 1; i <= N; i++)
	{
		// A + B = N - 1, B - A = arr[i + 1] - arr[i];
		int A = N - 1 + arr[i] - arr[i + 1];
		A /= 2;
		ans[A] = i;
	}
	answer(ans);
}
