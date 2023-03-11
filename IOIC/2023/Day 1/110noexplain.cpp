#pragma GCC optimize("Ofast,unroll-loops")
#include <cstdio>
int N;
signed main()
{
    scanf("%d", &N);
    printf("YES\n");
    for (int j = 0; j < (1 << (N + 1)); j++)
        printf("%d ", ((__builtin_popcount(j) & 1) ? 1 : 2));
}