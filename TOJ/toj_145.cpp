#pragma GCC optimize(",unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <stdio.h>
#pragma pack(1)
//#define getchar getchar_unlocked

unsigned short d[1002][1002], n, m, k, q, x1, y1, x2, y2, x = 0, y, c;

inline int read()
{
    x = 0, c = getchar();
    while (('0' > c || c > '9'))
        c = getchar();
    while ('0' <= c && c <= '9')
        x = x * 10 + (c ^ '0'), c = getchar();
    return x;
}

int main()
{
    n = read(), m = read(), k = read(), q = read();
    for (; k; k--)
    {
        x = read(), y = read();
        d[x + 1][y + 1]++;
    }
    for (unsigned short i = 0; i <= n; i++)
        for (unsigned short j = 2; j <= m; j++)
            d[i][j] += d[i][j - 1];

    for (unsigned short j = 0; j <= m; j++)
        for (unsigned short i = 2; i <= n; i++)
            d[i][j] += d[i - 1][j];

    for (; q; q--)
    {
        x1 = read(), y1 = read(), x2 = read(), y2 = read();
        x2++, y2++;
        printf("%d\n", d[x2][y2] - d[x1][y2] - d[x2][y1] + d[x1][y1]);
    }
}