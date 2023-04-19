#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;
 
int N, 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> M;
	
	for(int i = 1; i <= M; i++)
	{
		int A, B;
		cin >> A >> B;
		if(!adj[A][B])
		{	
			adj[A][B] = 1;
			v.emplace_back(pii(A, B));
		}
		for(int j = 0; j < N * N; j++)
		{
			if(j >= v.size())
				break;
			auto [x, y] = v[j];
			for(int z = 1; z <= N; z++)
				if(adj[y][z] && adj[z][y] && x != z && adj[x][z] == 0)
				{	
					adj[x][z] = 1;
					v.emplace_back(pii(x, z));
				}
			
			for(int z = 1; z <= N; z++)
				if(z != x && z != y && adj[y][x] && (adj[z][x] ^ adj[z][y]))
				{
					if(adj[z][x]) 
					{	
						adj[z][y] = 1;
						v.emplace_back(pii(z, y));
					}
					else
					{
						adj[z][x] = 1;
						v.emplace_back(pii(z, x));
					}
				}	
		}
		for(int x = 1; x <= N; x++)
			for(int y = 1; y <= N; y++)
				if(adj[x][y])
					for(int z = 1; z <= N; z++)
						if(adj[y][z] && adj[z][y] && x != z && adj[x][z] == 0)
							;//assert(false);
		cout << v.size() << '\n';
	}
}

