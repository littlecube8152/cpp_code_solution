#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int query(int x, int y, int z)
{
    printf("? %d %d %d\n", x, y, z);
    fflush(stdout);
    int ans = -1;
    (void)scanf("%d", &ans);
    if (ans == -1)
        exit(0);
    return ans;
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
    if (K == 1)
    {
        int L = 1, R = N;
        while (L < R)
        {
            int mans[1005][2] = {}, best = 1;
            int mid = (L + R) / 2;
            for (int i = 1; i <= M; i++)
            {
                mans[i][0] = query(mid, i, 1);
                mans[i][1] = query(mid + 1, i, 1);
                if (max(mans[best][0], mans[best][1]) < max(mans[i][0], mans[i][1]) ||
                    (max(mans[best][0], mans[best][1]) == max(mans[i][0], mans[i][1]) &&
                    min(mans[best][0], mans[best][1]) < min(mans[i][0], mans[i][1])))
                    best = i;
            }
            if (mans[best][0] <= mans[best][1])
                L = mid + 1;
            else
                R = mid;
            if(L == R)
                guess(L, best, 1);
        }
        
    }
}
/*
1 4 5 3
1 7 3 6
2 9 4 3
1 5 4 6
*/