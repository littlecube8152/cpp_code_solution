#include <iomanip>
#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
//#include <bits\stdc++.h>
using namespace std;
long double dots[200005][2];
int main()
{
    long double max_radius_sq = 0, min_radius_sq = 2000000, result, count, center[2];
    bool inner = false;
    cin >> count;
    if (count == 1)
    {
        cin >> count >> count >> count >> count;
        cout << "0.000\n";
        return 0;
    }

    for (int i = 0; i < count; i++)
    {
        cin >> dots[i][0] >> dots[i][1];
    }
    dots[(int)count][0] = dots[0][0];
    dots[(int)count][1] = dots[0][1];
    cin >> center[0] >> center[1];
    for (int i = 0; i < count; i++)
    {
        double radius_sq = pow(abs(dots[i][0] - center[0]), 2) + pow(abs(dots[i][1] - center[1]), 2);
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
        double lowest_distance_T = (-1) * ((dots[i][0] - center[0]) * (dots[i + 1][0] - dots[i][0]) + (dots[i][1] - center[1]) * (dots[i + 1][1] - dots[i][1])) / (pow(abs(dots[i][0] - dots[i + 1][0]), 2) + pow(abs(dots[i][1] - dots[i + 1][1]), 2));
        if (lowest_distance_T <= 1 && lowest_distance_T >= 0)
        {
            double slope = (dots[i + 1][1] - dots[i][1]) / (dots[i + 1][0] - dots[i][0]);
            double distance_sq = pow((slope * center[0] - center[1] + dots[i][1] - dots[i][0] * slope), 2) / (pow(slope, 2) + 1);
            if (distance_sq < min_radius_sq)
            {
                min_radius_sq = distance_sq;
                inner = true;
                cout << "Found a secant line\n";
            }
        }
    }
    result = M_PI * (max_radius_sq - min_radius_sq); 
    cout << setprecision(3) << fixed << result << '\n';
}