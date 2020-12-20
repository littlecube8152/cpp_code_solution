#include <bits/stdc++.h>
using namespace std;

int main()
{

    float x1, y1, r1, x2, y2, r2;
    while (cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2)
    {
        if (pow((x1 - x2), 2) + pow((y1 - y2), 2) <= pow((r1 + r2), 2) && r1 != 0 && r2 != 0)
        {
            cout << "Quick in\n";
        }
        else
        {
            cout << "Nearly\n";
        }
    }
}