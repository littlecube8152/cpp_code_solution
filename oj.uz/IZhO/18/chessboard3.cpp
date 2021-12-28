#include <bits/stdc++.h>
#define int long long
using namespace std;

/*************************************
 * 
 *  Without Subtask 4 : 70 points
 *  
 */
struct point
{
    int x1, y1, x2, y2;
};

signed main()
{

    int n, m, k, ans = 100000000000;
    cin >> n >> k;
    vector<point> v(k);
    vector<int> fac;
    for (int i = 0; i < k; i++)
        cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            fac.emplace_back(i);
            if (i * i != n && i != 1)
                fac.emplace_back(n / i);
        }
    }
    for (int i : fac)
    {
        int l = 0, r = 0;
        for (auto j : v)
            if (((j.x1 + i - 1) / i + (j.y1 + i - 1) / i) % 2)
                r++;
            else
                l++;
        //cout << i << " " << min({(n * n - i * i + 1) / 2 - l + r, (n * n - i * i) / 2 + l - r}) << '\n';
        if ((n / i) % 2)
            ans = min({ans, (n * n - i * i) / 2 + i * i - l + r, (n * n - i * i) / 2 + l - r});
        else
            ans = min({ans, (n * n) / 2 - l + r, (n * n) / 2 + l - r});
    }
    cout << ans << '\n';
}