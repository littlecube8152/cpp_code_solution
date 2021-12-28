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

    int xL = 1, xR = N, yL = 1, yR = M, zL = 1, zR = K;
    while (xL < xR || yL < yR || zL < zR)
    {
        int mans[205][205][2] = {};
        if (xL < xR)
        {
            int mid = (xL + xR) / 2, bestY = yL, bestZ = zL;
            for (int i = yL; i <= yR; i++)
                for (int j = zL; j <= zR; j++)
                {
                    mans[i][j][0] = query(mid, i, j);
                    mans[i][j][1] = query(mid + 1, i, j);
                    if (max(mans[bestY][bestZ][0], mans[bestY][bestZ][1]) < max(mans[i][j][0], mans[i][j][1]) ||
                        (max(mans[bestY][bestZ][0], mans[bestY][bestZ][1]) == max(mans[i][j][0], mans[i][j][1]) &&
                         min(mans[bestY][bestZ][0], mans[bestY][bestZ][1]) < min(mans[i][j][0], mans[i][j][1])))
                        bestY = i, bestZ = j;
                }
            if (mans[bestY][bestZ][0] <= mans[bestY][bestZ][1])
                xL = mid + 1;
            else
                xR = mid;
        }
        if (yL < yR)
        {
            int mid = (yL + yR) / 2, bestX = xL, bestZ = zL;
            for (int i = xL; i <= xR; i++)
                for (int j = zL; j <= zR; j++)
                {
                    mans[i][j][0] = query(i, mid, j);
                    mans[i][j][1] = query(i, mid + 1, j);
                    if (max(mans[bestX][bestZ][0], mans[bestX][bestZ][1]) < max(mans[i][j][0], mans[i][j][1]) ||
                        (max(mans[bestX][bestZ][0], mans[bestX][bestZ][1]) == max(mans[i][j][0], mans[i][j][1]) &&
                         min(mans[bestX][bestZ][0], mans[bestX][bestZ][1]) < min(mans[i][j][0], mans[i][j][1])))
                        bestX = i, bestZ = j;
                }
            if (mans[bestX][bestZ][0] <= mans[bestX][bestZ][1])
                yL = mid + 1;
            else
                yR = mid;
        }
        if (zL < zR)
        {
            int mid = (zL + zR) / 2, bestX = xL, bestY = yL;
            for (int i = xL; i <= xR; i++)
                for (int j = yL; j <= yR; j++)
                {
                    mans[i][j][0] = query(i, j, mid);
                    mans[i][j][1] = query(i, j, mid + 1);
                    if (max(mans[bestX][bestY][0], mans[bestX][bestY][1]) < max(mans[i][j][0], mans[i][j][1]) ||
                        (max(mans[bestX][bestY][0], mans[bestX][bestY][1]) == max(mans[i][j][0], mans[i][j][1]) &&
                         min(mans[bestX][bestY][0], mans[bestX][bestY][1]) < min(mans[i][j][0], mans[i][j][1])))
                        bestX = i, bestY = j;
                }
            if (mans[bestX][bestY][0] <= mans[bestX][bestY][1])
                zL = mid + 1;
            else
                zR = mid;
        }
    }
    guess(xL, yL, zL);
}
/*
1 4 5 3
1 7 3 6
2 9 4 3
1 5 4 6
*/