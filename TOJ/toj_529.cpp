#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#pragma pack(0)
#include <cstdio>
int a, b;
int main()
{
    scanf("%d %d", &a, &b);
    printf("%d\n", b - a);
}