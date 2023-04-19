#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, arr[303][303][303], ans = -1;



signed main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		arr[x][y][z] = 1;
	}
	const int C = 300;
	for(int i = 1; i <= C; i++)
	   	for(int j = 1; j <= C; j++)
	   		for(int k = 1; k <= C; k++)
		 		arr[i][j][k] = arr[i][j][k] +
							   arr[i - 1][j][k] + arr[i][j - 1][k] + arr[i][j][k - 1] +
						   	  -arr[i - 1][j - 1][k] - arr[i - 1][j][k - 1] - arr[i][j - 1][k - 1] +
					   		   arr[i - 1][j - 1][k - 1];
	for(int i = 1; i <= C; i++)
	   	for(int j = 1; j <= C; j++)
	   		for(int k = 1; k <= C; k++)
				if(arr[i][j - 1][k - 1] - arr[i - 1][j - 1][k - 1] > 0 &&
				   arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1] > 0 &&
				   arr[i - 1][j - 1][k] - arr[i - 1][j - 1][k - 1] > 0)
					ans = max(ans, i + j + k);


	cout << ans << '\n';
}
