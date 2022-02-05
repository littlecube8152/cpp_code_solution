#include <bits/stdc++.h>
using namespace std;

int T;
long long N;

void solve()
{
    cin >> N;
    if (N == 1)
    {
        cout << "= 1" << endl;
        return;
    }

    vector<int> v;

    for (int i = 0, j = (N + 1) / 2, k = 1; i < N;)
    {
        v.emplace_back(j);
        i++;
        j += i * k;
        k *= -1;
    }

    int mid = N / 2 - 1, res;
    cout << "? " << v[mid] << endl;
    cin >> res;
    cout << "? " << v[mid + 1] << endl;
    cin >> res;
    if (res == 1)
    {
        for (int i = mid + 1, j = v[mid + 1], k = v[mid] + (v[mid + 1] - v[mid]) / abs(v[mid + 1] - v[mid]); i > 1; i--)
        {
            cout << "? " << k << endl;
            cin >> res;
            if (res == 0)
            {
                cout << "= " << i << endl;
                return;
            }
            swap(j, k);
            k += (j - k) / abs(k - j);
        }
        cout << "= " << 1 << endl;
    }
    else
    {
        for (int i = mid + 2; i < N; i++)
        {
            cout << "? " << v[i] << endl;
            cin >> res;
            if (res == 1)
            {
                cout << "= " << i << endl;
                return;
            }
        }
        cout << "= " << N << endl;
    }
}

signed main()
{
    cin >> T;
    while (T--)
        solve();
}