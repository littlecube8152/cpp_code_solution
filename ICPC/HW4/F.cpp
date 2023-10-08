#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, grid[505][505];

signed main()
{
    cin >> N >> M;
    for (int i = 0; i <= max(N, M); i++)
        grid[i][M] = grid[N][i] = -1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];
    int x = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if(grid[i][j] >= 0 && grid[i][j + 1] < 0 && grid[i + 1][j] < 0)
                x ^= grid[i][j];
    cout << (x ? "first\n" : "second\n");
}