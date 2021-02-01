#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c, m, k, _max = 0, _min = 1000000000;
    vector<vector<int>> v(50, vector<int>(50, 0));
    cin >> r >> c >> k >> m;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> v[i][j];
    while (m--)
    {
        vector<vector<int>> cv(50, vector<int>(50, 0));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                if (v[i][j] == -1)
                {
                    cv[i][j] = -1;
                    continue;
                }
                cv[i][j] += v[i][j];
                if (i - 1 >= 0)
                    if (v[i - 1][j] >= 0)
                    {
                        cv[i - 1][j] += v[i][j] / k;
                        cv[i][j] -= v[i][j] / k;
                    }
                if (j - 1 >= 0)
                    if (v[i][j - 1] >= 0)
                    {
                        cv[i][j - 1] += v[i][j] / k;
                        cv[i][j] -= v[i][j] / k;
                    }
                if (i + 1 < r)
                    if (v[i + 1][j] >= 0)
                    {
                        cv[i + 1][j] += v[i][j] / k;
                        cv[i][j] -= v[i][j] / k;
                    }
                if (j + 1 < c)
                    if (v[i][j + 1] >= 0)
                    {
                        cv[i][j + 1] += v[i][j] / k;
                        cv[i][j] -= v[i][j] / k;
                    }
            }
        v = cv;
    }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            //cout << v[i][j] << " \n"[j == c - 1];
            _max = max(_max, v[i][j]);
            if (v[i][j] >= 0)
                _min = min(_min, v[i][j]);
        }
    cout << _min << '\n'
         << _max << '\n';
}