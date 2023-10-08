#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n = 200, k = 5;
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.emplace_back(i);
    mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(v.begin(), v.end(), rd);
    cout << n << ' ' << k << ' ' << n * (n - 1) / 2 << '\n';
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < k; j++)
            if (v[(i + j) % n] > v[i])
                cnt++;
        cerr << v[i] << " \n"[i == n - 1];
        cout << cnt << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            cout << i << ' ' << j << '\n';
}