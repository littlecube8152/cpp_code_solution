#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll T, N, t, sg[121] = {0, 1, 2, 3, 1, 4, 3, 2, 1, 4, 2, 6, 4, 1, 2, 7, 1, 4, 3, 2, 1, 4, 6, 7, 4, 1, 2, 8, 5, 4, 7, 2, 1, 8, 6, 7, 4, 1, 2, 3, 1, 4, 7, 2, 1, 8, 2, 7, 4, 1, 2, 8, 1, 4, 7, 2, 1, 4, 2, 7, 4, 1, 2, 8, 1, 4, 7, 2, 1, 8, 6, 7, 4, 1, 2, 8, 1, 4, 7, 2, 1, 8, 2, 7, 4, 1, 2, 8, 1, 4, 7, 2, 1, 8, 2, 7, 4, 1, 2, 8, 1, 4, 7, 2, 1, 8, 2, 7, 4, 1, 2, 8, 1, 4, 7, 2, 1, 8, 2, 7, 4};

int main()
{
    cin >> T;
    while (T--)
    {
        ll ans = 0, cycle, a;
        cin >> N >> t;
        cycle = t * 2LL + 3LL;
        for (int i = 1; i <= N; i++)
        {
            cin >> a;
            if (a <= t)
            {
                //cout << sg[0] << " ";
                continue;
            }
            a -= t;
            a = (a + t) / (t + 1LL);
            if (a >= 72)
            {
                ans ^= sg[(a % 12) + 72];
                //cout << sg[(a % 12) + 72] << " ";
            }
            else
            {
                ans ^= sg[a];
                //cout << sg[a] << " ";
            }
        }
        if (ans)
            cout << "Erste\n";
        else
            cout << "Zweite\n";
    }
}
// t = 0 : 0 [1 2 4]
// t = 1 : 0 0 [1 1 2 2 4]
// t = 2 : 0 0 0 [1 1 1 2 2 2 4]