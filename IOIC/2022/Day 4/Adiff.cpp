#pragma GCC optimize("Ofast,unroll-loops")
#pragma loop_opt(on)
#include <bits/stdc++.h>
using namespace std;
#define piii pair<pii, int>
#define pii pair<int, int>
#define F first
#define S second
#define ll long long
#define sub2(x) [(x).F][(x).S]
#define sub3(x) [(x).F.F][(x).F.S][(x).S]

int N, M;
char c[1005][1005];
piii v[2000005], u[2000005];
pii cur[2000005], pre[1005][1005], cmp[1005][1005][2];
int sa[1005][1005][2], tmp[1005][1005][2], cnt[2000005];
ll ans, two[1005] = {1}, three[1005] = {1};
const ll mod = 1000000007;

void radix_sort()
{
    int sz = N * M * 2;
    for (int i = 0; i <= 2000000; i++)
        cnt[i] = 0;
    for (int i = 0; i < sz; i++)
        cnt[cmp sub3(v[i]).S]++;
    for (int i = 1; i <= 2000000; i++)
        cnt[i] += cnt[i - 1];
    for (int i = sz - 1; i >= 0; i--)
        u[--cnt[cmp sub3(v[i]).S]] = v[i];
    for (int i = 0; i <= 2000000; i++)
        cnt[i] = 0;
    for (int i = 0; i < sz; i++)
        cnt[cmp sub3(u[i]).F]++;
    for (int i = 1; i <= 2000000; i++)
        cnt[i] += cnt[i - 1];
    for (int i = sz - 1; i >= 0; i--)
        v[--cnt[cmp sub3(u[i]).F]] = u[i];
}

int main()
{
    //ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> c[i][j];
    for (int i = 1; i <= max(N, M); i++)
    {
        c[i][0] = c[0][i] = '$';
        pre[i][0] = pii{i, 0};
        pre[0][i] = pii{0, i};
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            v[((i - 1) * M + (j - 1)) << 1] = piii{pii{i, j}, 0};
            cmp[i][j][0] = pii{c[i][j], c[i - 1][j]};
            v[((i - 1) * M + (j - 1)) << 1 | 1] = piii{pii{i, j}, 1};
            cmp[i][j][1] = pii{c[i][j], c[i][j - 1]};
            pre[i][j] = pii{i - 1, j - 1};
        }
    radix_sort();
    for (int k = 1; k <= 4000; k *= 2)
    {
        sa sub3(v[0]) = 1;
        for (int i = 1; i < N * M * 2; i++)
            if (cmp sub3(v[i]) != cmp sub3(v[i - 1]))
                sa sub3(v[i]) = i + 1;
            else
                sa sub3(v[i]) = sa sub3(v[i - 1]);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
            {
                cmp[i][j][0] = pii{sa[i][j][0], sa sub2(pre[i][j])[0]};
                cmp[i][j][1] = pii{sa[i][j][1], sa sub2(pre[i][j])[1]};
            }
        radix_sort();
        for (int i = N; i >= 1; i--)
            for (int j = M; j >= 1; j--)
                pre[i][j] = pre sub2(pre[i][j]);
    }
    for (int i = 1; i <= N; i++)
        two[i] = two[i - 1] * 2 % mod;
    for (int j = 1; j <= M; j++)
        three[j] = three[j - 1] * 3 % mod;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            ans = (ans + (two[i - 1] * three[j - 1] % mod) * (sa[i][j][0] + 5 * sa[i][j][1])) % mod;
    cout << ans << '\n';
}
