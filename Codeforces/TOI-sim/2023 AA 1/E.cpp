#include <bits/stdc++.h>
#define ll long long
using namespace std;

int x, y;

signed main()
{
    cin >> x >> y;
    if (y & 1)
    {
        cout << ":(\n";
        return 0;
    }
    if (y > x * 2)
    {
        cout << ":(\n";
        return 0;
    }
    int p = (2 * x - y) / 2;
    vector<int> ans;
    for (int i = 1; i <= p; i++)
    {
        ans.emplace_back(1);
        ans.emplace_back(0);
    }
    for (int i = 2 * p + 1; i <= y; i++)
        ans.emplace_back(1);
    cout << "[";
    for (int i = 0; i < y; i++)
        cout << (ans[i] ? "1" : "null") << ",]"[i + 1 == y];
}
