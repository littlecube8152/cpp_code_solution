#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct chess
{
    ll dis = _INFINITY;
    bool b = false;
};

ll n, x0, y0;
chess p[8];
//[0] [1] [2] [3] [4] [5] [6] [7]
// 0  90  180 270 45  135 215 315
//
//
//
//
//
//
//

int main()
{
    cin >> n >> x0 >> y0;
    while (n--)
    {
        char c;
        ll x, y;
        cin >> c >> x >> y;
        if (x == x0 && y > y0) //[0]
        {
            if ((c == 'R' || c == 'Q') && y - y0 < p[0].dis)
            {
                p[0].dis = y - y0;
                p[0].b = true;
            }
            else if ((c == 'B') && y - y0 < p[0].dis)
            {
                p[0].dis = y - y0;
                p[0].b = false;
            }
        }
        else if (y == y0 && x > x0) //[1]
        {
            if ((c == 'R' || c == 'Q') && x - x0 < p[1].dis)
            {
                p[1].dis = x - x0;
                p[1].b = true;
            }
            else if ((c == 'B') && x - x0 < p[1].dis)
            {
                p[1].dis = x - x0;
                p[1].b = false;
            }
        }
        else if (x == x0 && y < y0) //[2]
        {
            if ((c == 'R' || c == 'Q') && y0 - y < p[2].dis)
            {
                p[2].dis = y0 - y;
                p[2].b = true;
            }
            else if ((c == 'B') && y0 - y < p[2].dis)
            {
                p[2].dis = y0 - y;
                p[2].b = false;
            }
        }
        else if (y == y0 && x < x0) //[3]
        {
            if ((c == 'R' || c == 'Q') && x0 - x < p[3].dis)
            {
                p[3].dis = x0 - x;
                p[3].b = true;
            }
            else if ((c == 'B') && x0 - x < p[3].dis)
            {
                p[3].dis = x0 - x;
                p[3].b = false;
            }
        }
        else if (x - x0 == y - y0 && x - x0 > 0) //[4]
        {
            if ((c == 'B' || c == 'Q') && x - x0 < p[4].dis)
            {
                p[4].dis = x - x0;
                p[4].b = true;
            }
            else if ((c == 'R') && x - x0 < p[4].dis)
            {
                p[4].dis = x - x0;
                p[4].b = false;
            }
        }
        else if (x - x0 == y - y0 && x - x0 < 0) //[6]
        {
            if ((c == 'B' || c == 'Q') && x0 - x < p[6].dis)
            {
                p[6].dis = x0 - x;
                p[6].b = true;
            }
            else if ((c == 'R') && x0 - x < p[6].dis)
            {
                p[6].dis = x0 - x;
                p[6].b = false;
            }
        }
        else if (x - x0 + y - y0 == 0 && x - x0 > 0) //[5]
        {
            if ((c == 'B' || c == 'Q') && x - x0 < p[5].dis)
            {
                p[5].dis = x - x0;
                p[5].b = true;
            }
            else if ((c == 'R') && x - x0 < p[5].dis)
            {
                p[5].dis = x - x0;
                p[5].b = false;
            }
        }
        else if (x - x0 + y - y0 == 0 && x0 - x > 0) //[7]
        {
            if ((c == 'B' || c == 'Q') && x0 - x < p[7].dis)
            {
                p[7].dis = x0 - x;
                p[7].b = true;
            }
            else if ((c == 'R') && x0 - x < p[7].dis)
            {
                p[7].dis = x0 - x;
                p[7].b = false;
            }
        }
    }
    if (p[0].b || p[1].b || p[2].b || p[3].b || p[4].b || p[5].b || p[6].b || p[7].b)
        cout << "YES";
    else
        cout << "NO";
}