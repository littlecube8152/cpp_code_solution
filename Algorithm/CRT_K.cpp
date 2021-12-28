#include <bits/stdc++.h>
using namespace std;
vector<int> a = {2, 3, 2}, n = {3, 5, 7};

void exgcd(int a, int b, int c, int &x, int &y)
{
    if (b == 0)
        x = c / a, y = 0;
    else
    {
        exgcd(b, a % b, c, y, x);
        y -= x * (a / b);
    }
}

signed main()
{
    int N = 1, ans = 0, t, s;
    for (int i = 0; i < n.size(); i++)
        N *= n[i];
    for (int i = 0; i < n.size(); i++)
    {
        exgcd(N / n[i], n[i], 1, t, s);
        ans = (ans + N / n[i] * a[i] * t) % N;
    }
    cout << ans;
}