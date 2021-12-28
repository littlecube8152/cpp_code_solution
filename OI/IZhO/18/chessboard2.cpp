#include <bits/stdc++.h>
#define int long long
using namespace std;

/*************************************
 * 
 *  Subtask 1 : 8 points
 *  Subtask 2 : 8 points
 * 
 */

signed main()
{
    int n, m, k;
    vector<int> v;
    cin >> n >> k;
    if (k == 0) // Subtask 1
    {
        m = n;
        for (int i : {3, 5, 7, 11, 13, 17, 19, 23, 27, 29, 31, 37, 41, 43, 47, 53, 57, 61, 67, 71, 73, 79, 83, 89, 97})
            while (m % i == 0)
                v.emplace_back(i), m /= i;
        if (m > 1)
            v.emplace_back(m);

        if (n == (n & -n))
            cout << n * n / 2 << '\n';
        else
            cout << (n * n - (n / v[0]) * (n / v[0])) / 2;
    }
    else // Subtask 2
    {
        int l = 0, r = 0;
        for (int i = 1; i <= k; i++)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if ((x1 + y1) % 2)
                r++;
            else
                l++;
        }
        cout << min((n * n + 1) / 2 - l + r, (n * n) / 2 - r + l) << '\n';
        
    }
}