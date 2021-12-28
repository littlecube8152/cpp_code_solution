#include <bits/stdc++.h>
using namespace std;
long double dots[200005][2];
int main()
{
    long double max_radius_sq = 0, min_radius_sq = 2000000, result, count, center[2];
    bool inner = false;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> dots[i][0] >> dots[i][1];
    }
    dots[(int)count][0] = dots[0][0];
    dots[(int)count][1] = dots[0][1];
    cin >> center[0] >> center[1];
    for (int i = 0; i < count; i++)
    {
        long double radius_sq = ((dots[i][0] - center[0]) * (dots[i][0] - center[0])) + ((dots[i][1] - center[1]) * (dots[i][1] - center[1]));
        if (radius_sq > max_radius_sq)
        {
            max_radius_sq = radius_sq;
        }
        if (radius_sq < min_radius_sq)
        {
            min_radius_sq = radius_sq;
        }
    }
    for (int i = 0; i < count; i++)
    {
        long double lowest_distance_T = (-1) * ((dots[i][0] - center[0]) * (dots[i + 1][0] - dots[i][0]) + (dots[i][1] - center[1]) * (dots[i + 1][1] - dots[i][1])) /
                                            ((dots[i][0] - dots[i + 1][0]) * (dots[i][0] - dots[i + 1][0])) +
                                        ((dots[i][1] - dots[i + 1][1]) * (dots[i][1] - dots[i + 1][1]));
        if (lowest_distance_T <= 1 && lowest_distance_T >= 0)
        {
            long double slope = (dots[i + 1][1] - dots[i][1]) / (dots[i + 1][0] - dots[i][0]);
            long double distance_sq = ((slope * center[0] - center[1] + dots[i][1] - dots[i][0] * slope) * (slope * center[0] - center[1] + dots[i][1] - dots[i][0] * slope)) /
                                      (slope * slope);
            if (distance_sq < min_radius_sq)
            {
                min_radius_sq = distance_sq;
                inner = true;
            }
        }
    }
    result = acos(-1) * (max_radius_sq - (int)inner * min_radius_sq); //
    cout << fixed << setprecision(3) << result << '\n';
}
