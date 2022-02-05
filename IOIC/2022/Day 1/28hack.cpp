#pragma GCC target("rdrnd")
#include <bits/stdc++.h>
#include <immintrin.h>
using namespace std;

long long mul(long long a, long long n, long long MOD)
{
    long long res = 0, base = a;
    while (n)
    {
        if (n & 1)
            res = (res + base) % MOD;
        base = (base + base) % MOD;
        n >>= 1;
    }
    return res;
}

long long power(long long a, long long n, long long MOD)
{
    long long res = 1, base = a;
    while (n)
    {
        if (n & 1)
            res = mul(res, base, MOD);
        base = mul(base, base, MOD);
        n >>= 1;
    }
    return res;
}

bool is_fermat_pseudoprime(long long x)
{
    long long r = (long long)rand() * (long long)rand() % (x - 2) + 2;
    return (power(r, x - 1, x) == 1);
}

const int pre_proc_size = 1000001;
bool not_prime[pre_proc_size];

void init()
{
    not_prime[1] = 1;
    for (int i = 2; i < pre_proc_size; i++)
    {
        if (not_prime[i])
            continue;
        for (int j = i + i; j < pre_proc_size; j += i)
            not_prime[j] = 1;
    }
}

int main()
{
    uint32_t seed;
    _rdrand32_step(&seed);
    srand(seed);
    init();
    int T;
    cin >> T;
    while (T--)
    {
        long long x;
        cin >> x;
        if (x <= 1000000)
        {
            if (!not_prime[x])
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            continue;
        }
        else
        {
            if (is_fermat_pseudoprime(x))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}