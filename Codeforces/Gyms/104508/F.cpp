#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int far[40];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < 30; i++)
            far[i] = i;
        bitset<30> tot;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            bitset<30> b = a;
            tot |= b;
            for (int i = 29; i > 0; i--)
            {
                if (b[i] == 0)
                    continue;
                int j = i - 1;
                while (j && b[j] == 0)
                    j--;
                far[i] = min(far[i], j);
            }
        }
        for (int p = 28; p >= 0; p--)
            far[p] = min(far[p], far[p + 1]);
        for (int p = 29; p >= 0; p--)
            if (tot[p])
            {
                cout << (1 << (p + 1)) - 1 << ' ';
                int cost = 0;
                for (int j = p; j >= 0; j--)
                    if(tot[j] == 0)
                    {
                        cost++;
                        j = far[j + 1];
                    }
                cout << cost << '\n';
                break;
            }
    }
}