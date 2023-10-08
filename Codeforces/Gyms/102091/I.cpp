#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int T, N, M, A[1005][1005], bit[1005][1005], l[1005][1005], r[1005][1005], u[1005][1005], d[1005][1005];
ll P[1000006];
pii pos[1000006];
const ll mod = 3428977, base = 184903, C = 1'000'000;

void init()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            bit[i][j] = 0;
}

void modify(int i, int _j)
{
    for (; i <= N; i += i & -i)
        for (int j = _j; j <= M; j += j & -j)
            bit[i][j]++;
}

int query(int i, int _j)
{
    int ans = 0;
    for (; i; i -= i & -i)
        for (int j = _j; j; j -= j & -j)
            ans += bit[i][j];
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    P[0] = 1;
    for (int i = 1; i <= C; i++)
        P[i] = P[i - 1] * base % mod;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        ll ans = 0, sum = 0;
        cin >> N >> M;
        init();
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
            {
                cin >> A[i][j];
                pos[A[i][j]] = pii(i, j);
            }
        for (int i = 1; i <= N; i++)
            A[i][M + 1] = A[i][0] = M * N + 1;
        for (int i = 1; i <= M; i++)
            A[0][i] = A[N + 1][i] = M * N + 1;
        for (int i = 1; i <= N; i++)
        {
            vector<pii> mono = {pii(0, N * M + 1)};
            for (int j = 1; j <= M + 1; j++)
            {
                while (mono.back().S < A[i][j])
                    r[i][mono.back().F] = j, mono.pop_back();
                l[i][j] = mono.back().F;
                mono.push_back(pii(j, A[i][j]));
            }
        }
        for (int j = 1; j <= M; j++)
        {
            vector<pii> mono = {pii(0, N * M + 1)};
            for (int i = 1; i <= N + 1; i++)
            {
                while (mono.back().S < A[i][j])
                    u[mono.back().F][j] = i, mono.pop_back();
                d[i][j] = mono.back().F;
                mono.push_back(pii(i, A[i][j]));
            }
        }
        for (int k = 1; k <= N * M; k++)
        {
            auto [i, j] = pos[k];
            modify(i, j);
            if (A[i + 1][j] > A[i][j] && A[i][j + 1] > A[i][j]) // left down
                sum += query(i,       j) - query(i,       l[i][j]) - 
                       query(d[i][j], j) + query(d[i][j], l[i][j]);
            else if (A[i + 1][j] > A[i][j] && A[i][j - 1] > A[i][j]) // right down
                sum += query(i,       r[i][j] - 1) - query(i,       j - 1) - 
                       query(d[i][j], r[i][j] - 1) + query(d[i][j], j - 1);
            else if (A[i - 1][j] > A[i][j] && A[i][j - 1] > A[i][j]) // right up
                sum += query(u[i][j] - 1, r[i][j] - 1) - query(u[i][j] - 1, j - 1) - 
                       query(i - 1      , r[i][j] - 1) + query(i - 1      , j - 1);
            else if (A[i - 1][j] > A[i][j] && A[i][j + 1] > A[i][j]) // left up
                sum += query(u[i][j] - 1, j) - query(u[i][j] - 1, l[i][j]) - 
                       query(i - 1      , j) + query(i - 1      , l[i][j]);
            sum %= mod;
            ans = (ans + sum * P[k]) % mod;
        }

        cout << "Case " << t << ": " << ans << '\n';
    }
}