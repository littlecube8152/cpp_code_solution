#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;
vector<int> p;

int tri_search(int lower, int upper, int d)
{
    if (lower == upper - 1 || lower == upper)
        return min(lower + ceil(d / (lower + 1.0)), upper + ceil(d / (upper + 1.0)));
    if (lower == upper - 2)
        return min(lower+1 + ceil(d / (lower + 2.0)), min(lower + ceil(d / (lower + 1.0)), upper + ceil(d / (upper + 1.0))));
    int x1 = floor((2.0 * lower + upper) / 3.0), x2 = ceil((lower + 2.0 * upper) / 3.0);
    if (x1 + ceil(d / (x1 + 1.0)) < x2 + ceil(d / (x2 + 1.0)))
        return tri_search(lower, x2, d);
    else
        return tri_search(x1, upper, d);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        if (n >= tri_search(0, d - 1, d))
        {
            cout << "YES\n";
        }
        else
        {
            cout <<  "NO\n";
        }
    }
}