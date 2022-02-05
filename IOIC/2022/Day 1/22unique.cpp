#include <algorithm>
#include <stdio.h>
#define N 123456

double a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf", &a[i]);
    }
    int m = std::unique(a, a + n) - a;
    for (int i = 0; i < m; ++i)
    {
        if (i != 0)
        {
            putchar(' ');
        }
        printf("%.8f", a[i]);
    }
    putchar('\n');
    return 0;
}