#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, K, c[4005];
bitset<4005> b[4005];


signed main()
{
	cin >> N >> K;
	K += N - 1;
	for(int i = 1; i <= N; i++)
		b[i][i] = 1;
	for(int i = 1; i <= K; i++)
	{
		char t;
	   	int	A, B;
		cin >> t;
		if(t == 'C')
			cin >> A;
		else
			cin >> A >> B;
		
		if(t == 'S')
		{
			b[A] |= b[B];
			b[B] |= b[A];
		}
		else if(t == 'C')
		{
			int cnt = 0;
			for(int i = 1; i <= N; i++)
				cnt += b[i][A];	
			cout << cnt << '\n';
		}
		else if(t == 'Q')
			cout << (b[A][B] ? "yes\n" : "no\n");

	}	
}
