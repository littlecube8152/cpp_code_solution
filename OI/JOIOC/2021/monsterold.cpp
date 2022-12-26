#include "monster.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

bool result[1005][1005];

bool Fight(int a, int b)
{

}

vector<int> Solve(int N)
{
    vector<int> T(N, 0), S(N, 0);
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dis[i][j] = (i == j ? 0 : 1e9);

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (Query(i, j))
                dis[j][i] = 1;
            else
                dis[i][j] = 1;

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);


    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (dis[i][j] == N - 1)
                T[N - 1] = i, S[i] = N - 1;
    for (int i = N - 2; i >= 0; i--)
        for (int j = 0; j < N; j++)
            if (dis[T[i + 1]][j] == 1 && S[j] == 0)
            {
                T[i] = j;
                S[j] = i;
                break;
            }
    return S;
}
