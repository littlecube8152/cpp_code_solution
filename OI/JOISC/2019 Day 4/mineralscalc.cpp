#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int cost(int N, bool built)
{
	if(N == 1)
		return 0;
	int sum = N, L = N / 2, R = N - L;
	if(built)
	{	
		sum += R;
		sum += cost(L, 1);
		sum += cost(R, 0);
	}
	else
	{
		sum += N / 2;
		sum += cost(L, 1);
		sum += cost(R, 0);
	}
	return sum;
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	cout << 2 * N + cost(N, 1);
}
