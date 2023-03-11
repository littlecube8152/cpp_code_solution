#include <cstdio>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")

signed main()
{
    int n, x = 1, b = 2;
    scanf("%d", &n);
    while (n)
    {
        if (n & 1)
            x = x * b % 10006;
        b = b * b % 10006;
        n >>= 1;
    }
    scanf("%d", &b);
    n = 1;
    b %= 10007;
    while (x)
    {
        if (x & 1)
            n = n * b % 10007;
        b = b * b % 10007;
        x >>= 1;
    }
    printf("%d\n", n);
}