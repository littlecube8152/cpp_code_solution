#include "trilib.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> hull = {1, 2, 3};
bool side;

signed main()
{
    int N = get_n();
    side = is_clockwise(1, 2, 3);

    for (int i = 4; i <= N; i++)
    {
        //for (int j = 0; j < hull.size(); j++)
            //cerr << hull[j] << " \n"[j == hull.size() - 1];
        if (is_clockwise(hull.back(), i, hull.front()) == side)
        {
            //cerr << "insert" << i << '\n';
            hull.emplace_back(i);
            while (hull.size() >= 3 && is_clockwise(hull[hull.size() - 3], hull[hull.size() - 2], hull[hull.size() - 1]) != side)
                hull.erase(hull.begin() + (hull.size() - 2));
            while (hull.size() >= 3 && is_clockwise(hull[hull.size() - 1], hull[0], hull[1]) != side)
                hull.erase(hull.begin());
        }
        else
        {
            int L = 0, R = hull.size() - 1;
            while (R - L > 1)
            {
                int mid = (L + R) / 2;
                if (is_clockwise(hull[L], i, hull[mid]) == side)
                    R = mid;
                else
                    L = mid;
            }
            //cerr << i << "final range:" << L << ", " << R << '\n';
            if (is_clockwise(hull[L], i, hull[R]) == side)
            {
                //cerr << "insert" << i << '\n';
                hull.insert(hull.begin() + R, i);
                int pos = R;
                while (hull.size() >= 3 && is_clockwise(hull[pos], hull[(pos + 1) % hull.size()], hull[(pos + 2) % hull.size()]) != side)
                {
                    int poppos = (pos + 1) % hull.size();

                    hull.erase(hull.begin() + ((pos + 1) % hull.size()));

                    if (poppos < pos)
                        pos--;
                }
                while (hull.size() >= 3 && is_clockwise(hull[pos], hull[(pos + hull.size() - 1) % hull.size()], hull[(pos + hull.size() - 2) % hull.size()]) == side)
                {
                    int poppos = (pos + hull.size() - 1) % hull.size();

                    hull.erase(hull.begin() + ((pos - 1) % hull.size()));

                    if (poppos < pos)
                        pos--;
                }
            }
        }
    }
    give_answer(hull.size());
}




/*
6
1 1
4 3
2 2
1 4
5 1
3 2
*/