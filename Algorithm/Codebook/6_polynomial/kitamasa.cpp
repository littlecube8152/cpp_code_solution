ll fast_kitamasa(ll k, vector<base> A, vector<base> C)
{
    int n = A.size();
    C.emplace_back(mod - 1);
    vector<base> Q, R = {0, 1}, F = {1};

    R = div(R, C);
    while (k)
    {
        if (k & 1)
            F = div(mul(F, R), C);
        R = div(mul(R, R), C);
        k >>= 1;
    }
    ll ans = 0;
    for (int i = 0; i < F.size(); i++)
        ans = (ans + A[i] * F[i]) % mod;
    return ans;
}