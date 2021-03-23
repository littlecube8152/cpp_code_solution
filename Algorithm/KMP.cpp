#include <bits/stdc++.h>
using namespace std;

string a, b;
vector<int> f = {-1, 0};

signed main()
{
    cin >> a >> b;
    //Failure Function
    for (int i = 2, j = 1; i < b.size(); f.emplace_back(j++), i++)
    {
        while (b[j] != b[i] && j != -1)
            j = f[j];
    }
    //for (int i : f)
    //    cout << i << " ";
    //cout << '\n';
    //Matching
    for (int i = 0, j = 0; i - j <= a.size() - b.size() + 2; j++, i++)
    {
        //cout << "KMP " << i << j << '\n';
        while (j != -1 && a[i] != b[j]) //Keep try until not error
            j = f[j];
        if (j == b.size() - 1)
        {
            cout << i - j << '\n';
            j = f[j];
        }
    }
}