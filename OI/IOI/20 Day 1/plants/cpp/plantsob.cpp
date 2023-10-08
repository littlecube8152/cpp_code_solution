#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    vector<int> r(n);
    for (int i = 0; i < n; i++)
        cin >> r[i];
    for (int i = 0; i < n; i++)
        v.emplace_back(i);
    do
    {
        vector<int> u = v;
        bool sat = 1;
        for (int i = 0; i < n; i++)
        {
            u.emplace_back(v[i]);
            int cnt = 0;
            for (int j = i; j < i + k; j++)
                if (u[i] < u[j])
                    cnt++;
            if (cnt != r[i])
                sat = 0;
        }
        if (sat)
        {
            for (int i : v)
                cout << i << ' ';
            cout << '\n';
        }
    } while (next_permutation(v.begin(), v.end()));
}