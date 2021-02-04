//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bitset>
#include <stdio.h>
//#define getchar getchar_unlocked
using namespace std;

inline int_fast16_t read()
{
    int_fast16_t x = 0, c = getchar();
    while (('0' > c || c > '9'))
        c = getchar();
    while ('0' <= c && c <= '9')
        x = x * 10 + (c ^ '0'), c = getchar();
    return x;
}

int_fast16_t n, m, x, y;
bitset<10001> b;

int main()
{
    n = read();
    m = read();

    for (; m;m--)
    {
        x = read(), y = read();
        b[x].flip();
        b[y].flip();
    }
    puts(((b.count() <= 2) ? "YES" : "NO"));
}