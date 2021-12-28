#include <bits/stdc++.h>
using namespace std;

int T;
long long N;

void solve()
{
    cin >> N;

    for (int i = 0, j = (N + 1) / 2, k = 1; i < N;)
    {
        cout << "? " << j << endl;
        int res;
        cin >> res;
        if (i != 0 && res == 1)
        {
            cout << "= " << i << endl;
            return;
        }
        i++;
        j += i * k;
        k *= -1;
    }
    cout << "= " << N << endl;
}

signed main()
{
    cin >> T;
    while (T--)
        solve();
}