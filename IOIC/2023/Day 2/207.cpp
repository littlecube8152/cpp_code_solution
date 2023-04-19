#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, c[1000006], ans, dsu[100005];

int find(int k)
{
    return k == dsu[k] ? k : dsu[k] = find(dsu[k]);
}

bool merge(int x, int y)
{
    x = find(x), y = find(y);
    dsu[x] = y;
    return x != y;
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        dsu[i] = i;
        int a;
        cin >> a;
        if (c[a])
            ans += a;
        c[a] = i;
    }
    for (int i = 1000000; i >= 1; i--)
    {
        int prev = 0;
        for (int j = i; j <= 1000000; j += i)
            if (c[j])
            {
                if (prev && merge(prev, c[j]))
                    ans += i;
                prev = c[j];
            }
    }
    cout << ans << '\n';
}