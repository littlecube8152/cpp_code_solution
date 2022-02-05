#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC optimize("inline")
#pragma loop_opt(on)
#include <cstring>
#include <iostream>
using namespace std;
struct pii
{
    int first = 0, second = 0;
    bool operator!=(pii p)
    {
        return first != p.first || second != p.second;
    }
};
struct piii
{
    pii first;
    int second = 0;
};
//#define piii pair<pii, int>
//#define pii pair<int, int>
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
ll ans, two[1005] = {0, 1}, three[1005] = {0, 1};
const ll mod = 1000000007;

inline void radix_sort()
{
    int sz = N * M * 2;
    memset(cnt, 0, sizeof cnt);

    for (int i = 0; i < 2000000; ++i)
        cnt[cmp sub3(v[i]).S]++;

    for (int i = 1; i <= 2000000; ++i)
        cnt[i] += cnt[i - 1];
    for (int i = sz - 1; i >= 0; --i)
        u[--cnt[cmp sub3(v[i]).S]] = v[i];
    memset(cnt, 0, sizeof cnt);

    for (int i = 0; i < 2000000; ++i)
        cnt[cmp sub3(u[i]).F]++;

    for (int i = 1; i <= 2000000; ++i)
        cnt[i] += cnt[i - 1];
    for (int i = sz - 1; i >= 0; --i)
        v[--cnt[cmp sub3(u[i]).F]] = u[i];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)

        for (int j = 1; j <= M; ++j)
            cin >> c[i][j];
    cmp[0][0][0] = {2000001, 2000001};

    for (int i = 1; i <= 1000; ++i)
    {
        c[i][0] = c[0][i] = '$';
        pre[i][0] = pii{i, 0};
        pre[0][i] = pii{0, i};
    }
    int idx = 0;

    for (int i = 1; i <= N; ++i)

        for (int j = 1; j <= M; ++j)
        {
            v[idx++] = piii{pii{i, j}, 0};
            cmp[i][j][0] = pii{c[i][j], c[i - 1][j]};
            v[idx++] = piii{pii{i, j}, 1};
            cmp[i][j][1] = pii{c[i][j], c[i][j - 1]};
            pre[i][j] = pii{i - 1, j - 1};
        }
    radix_sort();
    for (int k = 1; k <= 1000; k <<= 1)
    {
        sa sub3(v[0]) = 1;

        for (int i = 1; i < 2000000; ++i)
            if (cmp sub3(v[i]) != cmp sub3(v[i - 1]))
                sa sub3(v[i]) = i + 1;
            else
                sa sub3(v[i]) = sa sub3(v[i - 1]);
        sa[0][0][0] = 0;

        for (int i = 1; i <= 1000; ++i)

            for (int j = 1; j <= 1000; ++j)
            {
                cmp[i][j][0] = pii{sa[i][j][0], sa sub2(pre[i][j])[0]};
                cmp[i][j][1] = pii{sa[i][j][1], sa sub2(pre[i][j])[1]};
            }
        radix_sort();

        for (int i = 1000; i >= 1; --i)

            for (int j = 1000; j >= 1; --j)
                pre[i][j] = pre sub2(pre[i][j]);
    }
    for (int i = 1; i < 2000000; ++i)
        if (cmp sub3(v[i]) != cmp sub3(v[i - 1]))
            sa sub3(v[i]) = i + 1;
        else
            sa sub3(v[i]) = sa sub3(v[i - 1]);

    for (int i = 2; i <= 1000; ++i)
        two[i] = two[i - 1] * 2 % mod;

    for (int j = 2; j <= 1000; ++j)
        three[j] = three[j - 1] * 3 % mod;

    for (int i = 1; i <= 1000; ++i)

        for (int j = 1; j <= 1000; ++j)
            ans = (ans + (two[i] * three[j] % mod) * (sa[i][j][0] + 5 * sa[i][j][1])) % mod;
    cout << ans << '\n';
}
