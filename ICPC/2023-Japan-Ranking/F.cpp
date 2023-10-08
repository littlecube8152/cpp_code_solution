#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

using Hash = valarray<ll>;
const Hash base = {300007, 300017, 300023}, mod = {1234567891, 1013295121, 200252531}, o = {0, 0, 0};
Hash bp[300005];

int N, M, L, A[300005], B[300005], nxt[300005], last[300005], C[300005];
vector<vector<ll>> v;
signed main()
{
    cin >> N >> M >> L;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= M; i++)
        cin >> B[i];

    bp[0] = {1, 1, 1};
    for (int i = 1; i <= M; i++)
        bp[i] = bp[i - 1] * base % mod;

    int K = 0;
    for (int i = 1; i <= M; i++)
    {
        if (last[B[i]])
            nxt[last[B[i]]] = i;
        else
            K++;
        last[B[i]] = i;
    }
    fill(B, B + M + 1, 0);
    for (int i = 1; i <= M; i++)
        if (nxt[i])
            B[nxt[i]] = nxt[i] - i;

    fill(last, last + L + 1, 0);
    fill(nxt, nxt + N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        if (last[A[i]])
            nxt[last[A[i]]] = i;
        last[A[i]] = i;
    }
    for (int i = 1; i <= N; i++)
        if (nxt[i])
            C[nxt[i]] = nxt[i] - i;

    Hash a = o, b = o, c = o;
    for (int i = 1; i <= M; i++)
    {
        a = (a * base + Hash(A[i], 3)) % mod;
        b = (b * base + Hash(B[i], 3)) % mod;
        c = (c * base + Hash(C[i], 3)) % mod;
    }

    for (int i = 1; i + M - 1 <= N; i++)
    {

        if ((b == c).min())
            v.emplace_back(vector<ll>(begin(a), end(a)));
        a = (a - (bp[M - 1] * A[i] % mod) + mod) % mod;
        c = (c - (bp[M - 1] * C[i] % mod) + mod) % mod;

        if (nxt[i])
        {
            int j = nxt[i];
            if (j <= i + M - 1)
                c = (c - (bp[i + M - 1 - j] * C[j] % mod) + mod) % mod;
            C[j] = 0;
        }
        a = (a * base + Hash(A[i + M], 3)) % mod;
        c = (c * base + Hash(C[i + M], 3)) % mod;
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    ll ans = v.size();
    cerr << ans << '\n';
    for (int i = 1; i <= L - K; i++)
        ans = ans * i % 998244353;
    cout << ans << '\n';
}