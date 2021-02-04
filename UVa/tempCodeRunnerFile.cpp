#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int n, k, a[505];

string itos(int n)
{
    stringstream ss;
    string s;
    ss << n;
    ss >> s;
    return s;
}

void bs(int L, int R)
{
    int mid = (L + R) / 2, sum = 0, t = 0;
    if (L == R)
    {
        set<int> v;
        k--;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i < k || sum + a[i] > L)
            {
                k--;
                v.insert(i);
                sum = 0;
            }

            sum += a[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (v.count(i))
                cout << a[i] << " /"
                     << " \n"[i == n - 1];
            else
                cout << a[i] << " \n"[i == n - 1];
        }

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] > mid)
        {
            t++;
            sum = 0;
        }
        sum += a[i];
    }
    if (sum > 0)
        t++;

    if (t > k)
        bs(mid + 1, R);
    else
        bs(L, mid);
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int sum = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            sum += a[i];
        bs(0, sum);
    }
}