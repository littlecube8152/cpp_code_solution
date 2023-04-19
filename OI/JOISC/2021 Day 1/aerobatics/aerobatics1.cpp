#include "aerobatics.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

double GetAngle(pii a, pii b, pii c)
{
    return GetAngle(a.F, a.S, b.F, b.S, c.F, c.S);
}

int N, Z, ori[16][16][1 << 16] = {{}};
double dp[16][16][1 << 16] = {{}};

void solve(ifstream cin, ofstream cout)
{

    pii p[16];
    cin >> N >> Z;
    for (int i = 0; i < N; i++)
        cin >> p[i].F >> p[i].S;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int mask = 0; mask < (1 << N); mask++)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j)
                dp[i][j][(1 << i) ^ (1 << j)] = 180.0;
    for (int mask = 0; mask < (1 << N); mask++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (i != j)
                    if ((mask & (1 << i)) != 0 && (mask & (1 << j)) != 0)
                        for (int k = 0; k < N; k++)
                            if ((mask & (1 << k)) == 0)
                                if (dp[j][k][mask ^ (1 << k)] < min(dp[i][j][mask], GetAngle(p[j], p[i], p[k])))
                                    dp[j][k][mask ^ (1 << k)] = min(dp[i][j][mask], GetAngle(p[j], p[i], p[k])), ori[j][k][mask ^ (1 << k)] = i;

    int besti = 0, bestj = 1, mask = (1 << N) - 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cerr << i << " " << j << " " << dp[i][j][mask] << '\n';
            if (i != j)
                if (dp[i][j][mask] > dp[besti][bestj][mask])
                    besti = i, bestj = j;
        }
    cerr << dp[besti][bestj][mask] << '\n';
    cout << bestj + 1 << '\n'
         << besti + 1 << '\n';
    for (int i = 1; i <= N - 2; i++)
    {
        cout << ori[besti][bestj][mask] + 1 << '\n';
        int newmask = mask ^ (1 << bestj), newi = ori[besti][bestj][mask], newj = besti;
        besti = newi;
        bestj = newj;
        mask = newmask;
    }
}

signed main()
{
    // solve(ifstream("sample-01.txt"), ofstream("outputsample_01.txt"));
    solve(ifstream("input_01.txt"), ofstream("output_01.txt"));
}