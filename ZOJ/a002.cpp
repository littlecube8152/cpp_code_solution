//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <stdio.h>
//#define getchar getchar_unlocked

inline int read()
{
    int x = 0, c = getchar(), neg = false;
    while (('0' > c || c > '9') && c != '-' && c != EOF)
        c = getchar();
    if (c == '-')
        neg = true, c = getchar();
    while ('0' <= c && c <= '9')
        x = x * 10 + (c ^ '0'), c = getchar();
    if (neg)
        x = -x;
    return x; // returns 0 if EOF
}

int x, y;

int main()
{
    x = read(), y = read();
    x = x + y;
    printf("%d\n", x);
}