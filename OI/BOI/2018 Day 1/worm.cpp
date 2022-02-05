#include <bits/stdc++.h>
using namespace std;

map<int, int> arr;
int N, M, K, Q;

int query(int x, int y, int z)
{
    if (1 <= x && x <= N && 1 <= y && y <= M && 1 <= z && z <= K && arr[x * (M * K) + y * K + z] == 0)
    {
        printf("? %d %d %d\n", x, y, z);
        fflush(stdout);
        int ans = -1;
        (void)scanf("%d", &ans);
        if (ans == -1)
            exit(0);
        arr[x * (M * K) + y * K + z] = ans;
    }
    return arr[x * (M * K) + y * K + z];
}

void guess(int x, int y, int z)
{
    printf("! %d %d %d\n", x, y, z);
    exit(0);
}

const double phi = 0.618033988749894848204586;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int main()
{

    (void)scanf("%d %d %d %d", &N, &M, &K, &Q);
    if (M == 1 && K == 1)
    {
        int L = 1, R = N;
        int lmid = round(phi * L + (1.0 - phi) * R), rmid = round((1.0 - phi) * L + phi * R);
        while (R - L >= 3)
        {

            int lans = query(lmid, 1, 1), rans = query(rmid, 1, 1);
            if (lans >= rans)
            {
                R = rmid - 1;
                rmid = lmid;
                lmid = round(phi * L + (1.0 - phi) * R);
            }
            else
            {
                L = lmid + 1;
                lmid = rmid;
                rmid = round((1.0 - phi) * L + phi * R);
            }
        }
        for (int i = L; i <= R; i++)
            if (query(i - 1, 1, 1) <= query(i, 1, 1) && query(i, 1, 1) >= query(i + 1, 1, 1))
                guess(i, 1, 1);
    }
    else if (K == 1)
    {
        int xL = 1, xR = N, yL = 1, yR = M;
        int bestX = 1, bestY = 1, bestAns = 0;
        while (xL < xR || yL < yR)
        {

            //printf("(%d, %d) (%d, %d)\n", xL, xR, yL, yR);
            if (xL < xR)
            {
                int mid = (xL + xR) / 2, pivot = yL;
                for (int i = yL; i <= yR; i++)
                {
                    if (query(mid, i, 1) > query(mid, pivot, 1))
                        pivot = i;
                    if (query(mid, i, 1) > bestAns)
                        bestX = mid, bestY = i, bestAns = query(mid, i, 1);
                }
                int lans = query(mid, pivot, 1), rans = query(mid + 1, pivot, 1);
                if (max(lans, rans) < bestAns)
                {
                    if (bestX <= mid)
                        xR = mid;
                    else
                        xL = mid + 1;
                }
                else
                {
                    if (lans >= rans)
                        xR = mid;
                    else
                        xL = mid + 1;
                }
                if (lans > bestAns)
                    bestX = mid, bestY = pivot, bestAns = lans;
                if (rans > bestAns)
                    bestX = mid + 1, bestY = pivot, bestAns = rans;
            }
            //printf("(%d, %d) (%d, %d)\n", xL, xR, yL, yR);
            if (yL < yR)
            {

                int mid = (yL + yR) / 2, pivot = xL;
                for (int i = xL; i <= xR; i++)
                {
                    if (query(i, mid, 1) > query(pivot, mid, 1))
                        pivot = i;
                    if (query(i, mid, 1) > bestAns)
                        bestX = i, bestY = mid, bestAns = query(i, mid, 1);
                }
                int lans = query(pivot, mid, 1), rans = query(pivot, mid + 1, 1);
                if (max(lans, rans) < bestAns)
                {
                    if (bestY <= mid)
                        yR = mid;
                    else
                        yL = mid + 1;
                }
                else
                {
                    if (lans >= rans)
                        yR = mid;
                    else
                        yL = mid + 1;
                }
                if (lans > bestAns)
                    bestX = pivot, bestY = mid, bestAns = lans;
                if (rans > bestAns)
                    bestX = pivot, bestY = mid + 1, bestAns = rans;
            }
        }
        guess(xL, yL, 1);
    }
    else
    {
        int bestX = 1, bestY = 1, bestZ = 1, bestAns = 0;
        int i = 1;
        for (; i <= Q / 2; i++)
        {
            int x = abs((int)rd()) % N + 1;
            int y = abs((int)rd()) % M + 1;
            int z = abs((int)rd()) % K + 1;
            assert(x <= N);
            assert(y <= M);
            assert(z <= K);
            int ans = query(x, y, z);
            if (ans > bestAns)
                bestAns = ans, bestX = x, bestY = y, bestZ = z;
        }
        while (1)
        {
            int x = bestX, y = bestY, z = bestZ;
            for (int dx = -1; dx <= 1; dx++)
                for (int dy = -1; dy <= 1; dy++)
                    for (int dz = -1; dz <= 1; dz++)
                        if (abs(dx) + abs(dy) + abs(dz) == 1)
                        {
                            int ans = query(x + dx, y + dy, z + dz);
                            if (ans > bestAns)
                            {
                                bestAns = query(x + dx, y + dy, z + dz);
                                bestX = x + dx, bestY = y + dy, bestZ = z + dz;
                                goto next;
                            }
                        }
        next:
            bestX += 0;
            if (x == bestX && y == bestY && z == bestZ)
                break;
        }

        guess(bestX, bestY, bestZ);
    }
}
//   x ---->
// y 1 4 2 5 8
// | 1 3 6 3 2
// | 2 5 9 8 7
// v 3 5 4 7 6
//   1 7 5 4 3