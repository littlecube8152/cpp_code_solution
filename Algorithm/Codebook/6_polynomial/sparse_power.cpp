vector<ll> fpow(vector<ll> f, ll p, ll m)
{
    int b = 0;
    while (b < f.size() && f[b] == 0)
        b++;
    f = vector<ll>(f.begin() + b, f.end());
    int n = f.size();
    f.emplace_back(0);
    vector<ll> q(min(m, b * p), 0);
    q.emplace_back(fpow(f[0], p));
    for (int k = 0; q.size() < m; k++)
    {
        ll res = 0;
        for (int i = 0; i < min(n, k + 1); i++)
            res = (res + p * (i + 1) % mod * f[i + 1] % mod * q[k - i + b * p]) % mod;
        for (int i = 1; i < min(n, k + 1); i++)
            res = (res - f[i] * (k - i + 1) % mod * q[k - i + 1 + b * p]) % mod;
        res = (res < 0 ? res + mod : res) * inv(f[0] * (k + 1) % mod) % mod;
        q.emplace_back(res);
    }
    return q;
}