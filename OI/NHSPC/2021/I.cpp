#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
using namespace std;

const ll MOD = 1000000007;

ll T;

vector<vector<ll>> P(9, vector<ll>(9, 0)),
I(9, vector<ll>(9, 0));

vector<vector<ll>> mul(vector<vector<ll>> m1, vector<vector<ll>> m2)
{
    vector<vector<ll>> res(9, vector<ll>(9, 0));
    for (int i = 0; i <= 8; i++)
        for (int k = 0; k <= 8; k++)
            for (int j = 0; j <= 8; j++)
                res[i][j] = (res[i][j] + m1[i][k] * m2[k][j]) % MOD;
    return res;
}

void fastpow(ll p)
{
    while (p > 0)
    {
        if (p & 1)
            I = mul(I, P);
        p >>= 1;
        P = mul(P, P);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    for (int i = 0; i < 7; i++)
        I[i][i] = 1;
    P[0][1] = P[0][4] = P[1][6] = P[2][1] = P[2][5] = P[3][3] = P[3][1] = P[3][0] = P[3][2] = P[4][4] = P[4][1] = P[5][5] = P[5][1] = P[6][3] = P[6][0] = P[6][2] = P[6][1] = 1;
    if (T == 1)
        cout << 0 << '\n';
    else
    {    fastpow(T - 1);
    cout << I[6][1] << '\n';}
}