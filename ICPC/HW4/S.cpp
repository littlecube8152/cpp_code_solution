#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
ll fpow(ll b, ll p)
{
    ll a = 1;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        p >>= 1;
        b = b * b % mod;
    }
    return a;
}

ll inv(ll b)
{
    return fpow(b, mod - 2);
}

int N, M;
ll A[505][505], b[505], pivot[505];

signed main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> A[i][j];
    for (int i = 1; i <= N; i++)
        cin >> b[i];
    int R = 0;
    for (int i = 1; i <= N; i++)
    {
        int r = i, f = M + 1;
        for (int j = i; j <= N; j++)
        {
            int k = 0;
            for (; k <= M; k++)
                if (A[j][k])
                    break;
            if (k < f)
                r = j, f = k;
        }
        if (f > M)
            break;
        pivot[f] = i;
        R++;
        for (int j = f; j <= M; j++)
            swap(A[i][j], A[r][j]);
        swap(b[i], b[r]);
        for (int j = f + 1; j <= M; j++)
            A[i][j] = A[i][j] * inv(A[i][f]) % mod;
        b[i] = b[i] * inv(A[i][f]) % mod;
        A[i][f] = 1;
        for (int j = 1; j <= N; j++)
            if (j != i)
            {
                for (int k = f + 1; k <= M; k++)
                    A[j][k] = ((A[j][k] - A[j][f] * A[i][k]) % mod + mod) % mod;
                b[j] = ((b[j] - A[j][f] * b[i]) % mod + mod) % mod;
                A[j][f] = 0;
            }
    }
    for (int i = R + 1; i <= N; i++)
        if (b[i])
        {
            cout << "-1\n";
            return 0;
        }
    cout << M - R << '\n';
    for (int i = 1; i <= M; i++)
        cout << b[pivot[i]] << " \n"[i == M];
    for (int i = 1; i <= M; i++)
        if (!pivot[i])
        {
            for (int j = 1; j <= M; j++)
            {
                ll val = 0;
                if (i == j)
                    val = mod - 1;
                else if(pivot[j])
                    val = A[pivot[j]][i];
                cout << val << " \n"[j == M];
            }
        }
}