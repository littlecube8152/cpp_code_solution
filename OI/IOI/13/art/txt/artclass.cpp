#include "artclass.h"
#include <bits/stdc++.h>
using namespace std;

int style(int H, int W, int R[500][500], int G[500][500], int B[500][500])
{

    double diff = 0, diff4 = 0;
    double black = 0;
    double toosimilar = 0;
    for (int i = 3; i + 3 < H; i++)
        for (int j = 3; j + 3 < W; j++)
        {
            if (R[i][j] * R[i][j] + G[i][j] * G[i][j] + B[i][j] * B[i][j] >= 3 * 180 * 180)
                black++;
            double avgR = 0, avgG = 0, avgB = 0;
            for (int x = i - 3; x <= i + 3; x++)
                for (int y = j - 3; y <= j + 3; y++)
                {
                    avgR += R[x][y], avgG += G[x][y], avgB += B[x][y];
                    diff += (R[i][j] - R[x][y]) * (R[i][j] - R[x][y]) +
                            (G[i][j] - G[x][y]) * (G[i][j] - G[x][y]) +
                            (B[i][j] - B[x][y]) * (B[i][j] - B[x][y]);
                }
            avgR /= 49, avgB /= 49, avgG /= 49;
            diff4 += (R[i][j] - avgR) * (R[i][j] - avgR) +
                     (G[i][j] - avgG) * (G[i][j] - avgG) +
                     (B[i][j] - avgB) * (B[i][j] - avgB);
            if ((R[i][j] - avgR) * (R[i][j] - avgR) +
                    (G[i][j] - avgG) * (G[i][j] - avgG) +
                    (B[i][j] - avgB) * (B[i][j] - avgB) <=
                3 * 5 * 5)
                toosimilar++;
        }
    diff /= (H - 6) * (W - 6);
    diff4 /= (H - 6) * (W - 6);
    black /= (H - 6) * (W - 6);
    toosimilar /= (H - 6) * (W - 6);
    // cout << fixed << setprecision(2) << diff << ' ' << diff4 << "(" << log10(diff4) << ")" << ' ' << black << ' ' << toosimilar << '\n';
    if (diff4 <= 260.0)
        return 4;
    if (toosimilar <= 0.1)
        return 3;
    if (diff4 >= 1800.0)
        return 3;
    if (diff <= 40000.0)
        return 4;
    if (black >= 0.2 && diff >= 210000.0)
        return 1;
    if (black >= 0.4)
        return 1;
    if (toosimilar >= 0.5)
        return 1;
    return 2;
}