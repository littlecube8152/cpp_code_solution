#include <bits/stdc++.h>
using namespace std;

/*************************************
 * 
 *  Subtask 1 : 8 points
 * 
 */

signed main()
{
    int n, m, k;
    vector<int> v;
    cin >> n >> k;
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