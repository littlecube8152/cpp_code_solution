
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, R, C, c1, c2, dp[105][105], res[105][105], dis[105][105], resdis[105][105];
char c;
queue<pii> q;
constexpr int P = 1e9 + 7;

#ifdef EVAL
#include "arithmetics.h"
#else
int Add(int a, int b)
{
    int ret = a % P;
    ret = (ret < 0 ? P + ret : ret) + (b % P);
    return (ret >= 0 ? ret % P : ret + P);
}
int Sub(int a, int b)
{
    int ret = a % P;
    ret = (ret < 0 ? P + ret : ret) - (b % P);
    return (ret >= 0 ? ret % P : ret + P);
}
int Mul(int a, int b)
{
    int ret = (1ll * (a % P) * (b % P)) % P;
    return (ret < 0 ? P + ret : ret);
}
int modpow(int base, int exp, int modulus = P)
{
    base %= modulus;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (1ll * result * base) % modulus;
        base = (1ll * base * base) % modulus;
        exp >>= 1;
    }
    return result;
}
int modinv(int a, int modulus = P)
{
    return modpow(a, modulus - 2);
}
int Div(int a, int b)
{
    int ret = b % P;
    ret = (1ll * (a % P) * modinv(ret < 0 ? P + ret : ret)) % P;
    return (ret < 0 ? P + ret : ret);
}
#endif

signed main()
{
    //ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> R >> C >> N;
    for (int i = 1; i <= C; i++)
    {
        for (int x = 1; x <= R; x++)
            for (int y = 1; y <= C; y++)
                dp[x][y] = 0, dis[x][y] = R;
        q.push(pii{1, i});
        dis[1][i] = 0, dp[1][i] = 1;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int i = min(R - x, C - y); i >= 1; i--)
                if (x + i <= R && y + i <= C)
                {
                    if (dis[x + i][y + i] > dis[x][y] + 1)
                    {
                        dis[x + i][y + i] = dis[x][y] + 1;
                        q.push(pii{x + i, y + i});
                        dp[x + i][y + i] = dp[x][y];
                    }
                    else if (dis[x + i][y + i] == dis[x][y] + 1)
                        dp[x + i][y + i] = Add(dp[x + i][y + i], dp[x][y]);
                    else
                        break;
                }
                else
                    break;
            for (int i = min(R - x, y - 1); i >= 1; i--)
                if (x + i <= R && y - i >= 1)
                {
                    if (dis[x + i][y - i] > dis[x][y] + 1)
                    {
                        dis[x + i][y - i] = dis[x][y] + 1;
                        q.push(pii{x + i, y - i});
                        dp[x + i][y - i] = dp[x][y];
                    }
                    else if (dis[x + i][y - i] == dis[x][y] + 1)
                        dp[x + i][y - i] = Add(dp[x + i][y - i], dp[x][y]);
                    else
                        break;
                }
                else
                    break;
        }
        for (int x = 1; x <= R; x++)
            for (int y = 1; y <= C; y++)
                cout << dp[x][y] << " \n"[y == C];
        cout << '\n';
        for (int j = 1; j <= C; j++)
            res[i][j] = dp[R][j], resdis[i][j] = dis[R][j];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> c >> c1 >> c2;
        if (c == 'B')
        {
            if ((1 + c1) % 2 != (R + c2) % 2 )
                cout << "0 0\n";
            else
                cout << resdis[c1][c2] << " " << res[c1][c2] << '\n';
        }
        else
            break;
    }
}