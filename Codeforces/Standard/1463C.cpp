#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int k, t = 0, x = 0, result = 0, t_q, x_q;
        bool success = 0;
        cin >> k;
        while (k--)
        {
            cin >> t_q >> x_q;
            if (t <= t_q)
            {

                if (success || k == 0)
                    result++;
                success = 1;
                t = t_q + abs(x_q - x);
                x = x_q;
            }
            else
            {
                success = 0;
            }
        }
        cout << "                              " << result << '\n';
    }
}