#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353, P = 20;
ll N, a[80004], d[80004], deg[80004], exist[1 << 20], inv[80004], dsu[80004], mul[80004], ans[80004];

int find(int k)
{
    return k == dsu[k] ? k : dsu[k] = find(dsu[k]);
}

void modify(int k, int i, ll val)
{
    // cout << k << ": ";
    k = find(k);
    // cout << mul[k] << " -> ";
    ans[i] = (ans[i] - mul[k]) % mod;
    if (mul[k] == 0)
        mul[k] = 1;
    mul[k] = mul[k] * val % mod;
    // cout << mul[k] << "\n";
    ans[i] = (ans[i] + mul[k]) % mod;
}

void merge(int a, int b, int i)
{
    a = find(a), b = find(b);
    if(a == b)
        return;
    ans[i] = (ans[i] - mul[a] - mul[b]) % mod;
    dsu[b] = a;
    mul[a] = mul[a] * mul[b] % mod;
    ans[i] = (ans[i] + mul[a]) % mod;
}

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        dsu[i] = i;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++)
        cin >> d[i];
    inv[1] = 1;
    for (int i = 2; i <= N; i++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for (int t = N; t >= 1; t--)
    {
        int i = d[t];
        ans[t] = ans[t + 1];
        for (int j = 0; j < P; j++)
            for (int k = j + 1; k < P; k++)
            {
                int p = exist[a[i] ^ (1 << j) ^ (1 << k)];
                if (p)
                {
                    modify(p, t, (deg[p] == 0 ? 1 : inv[deg[p]]) * (deg[p] + 1) % mod);
                    deg[p]++;
                    modify(i, t, (deg[i] == 0 ? 1 : inv[deg[i]]) * (deg[i] + 1) % mod);
                    deg[i]++;
                    merge(p, i, t);
                }
            }
        for (int j = 0; j < P; j++)
        {
            int p = exist[a[i] ^ (1 << j)];
            if (p)
            {
                modify(p, t, (deg[p] == 0 ? 1 : inv[deg[p]]) * (deg[p] + 1) % mod);
                deg[p]++;
                modify(i, t, (deg[i] == 0 ? 1 : inv[deg[i]]) * (deg[i] + 1) % mod);
                deg[i]++;
                merge(p, i, t);
            }
        }
        // for (int i = 1; i <= N; i++)
        //     cout << deg[i] << " \n"[i == N];
        exist[a[i]] = i;
    }
    for (int i = 1; i <= N; i++)
        cout << (ans[i] + mod) % mod << '\n';
}
