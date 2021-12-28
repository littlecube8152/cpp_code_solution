#include <stdio.h>
#include <stdlib.h>

int arr[1000005];

int query(int x, int y, int z)
{
    if (arr[x] == 0)
    {
        printf("? %d %d %d\n", x, y, z);
        fflush(stdout);
        int ans = -1;
        (void)scanf("%d", &ans);
        if (ans == -1)
            exit(0);
        arr[x] = ans;
    }
    return arr[x];
}

__attribute__((noreturn)) void guess(int x, int y, int z)
{
    printf("! %d %d %d\n", x, y, z);
    exit(0);
}

int main()
{
    int N, M, K, Q;
    (void)scanf("%d %d %d %d", &N, &M, &K, &Q);
    if (M == 1 && K == 1)
    {
        int L = 1, R = N;
        while (L < R && Q >= 0)
        {
            int mid = (L + R) / 2;
            if (--Q < 0)
                break;
            int lans = query(mid, 1, 1);
            if (arr[L] != 0 && arr[R] != 0)
            {
                if (arr[L] <= lans && lans <= arr[R])
                    L = mid + 1;
                else if (arr[L] >= lans && lans >= arr[R])
                    R = mid;
                else
                    goto otherwise;
            }
            else
            {
            otherwise:
                if (--Q < 0)
                    break;
                int rans = query(mid + 1, 1, 1);
                if (lans <= rans)
                    L = mid + 1;
                else
                    R = mid;
            }
        }
        guess((L + R) / 2, 1, 1);
    }
}
// 1 4 6 3 7 | 2 9 8 5 19 | 4 3