#include <bits/stdc++.h>
using namespace std;

int main()
{

    long double x1, y1, r1, x2, y2, r2;
    while (cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2)
    {
        if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)  <=  (r1 + r2) * (r1 + r2)+ 0.0000001)
            cout << "Quick in\n";
        else
            cout << "Nearly\n";
    }
}