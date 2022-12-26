#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;


pii decode(ll p, int N)
{
	ll acc = 0;
	for(int i = 0; i < N; i++)
		if(acc <= p && p < acc + N - i - 1)
			return pii(i, i + 1 + p - acc);
		else 
			acc += N - i - 1;
	assert(0);
}

ll encode(int x, int y, int N)
{
	ll acc = 0;
	for(int i = 0; i < x; i++)
		acc += N - i - 1;
	return acc + y - x - 1;
}


signed main()
{
	int N;
	while(cin >> N)
	for(int i = 0; i < N; i++)
		for(int j = i + 1; j < N; j++)
			if(pii(i, j) != decode(encode(i, j, N), N))
				cout << i << ' ' << j << ' ' << N << " isn't satisfied.\n";		
}
