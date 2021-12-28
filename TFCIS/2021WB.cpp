#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
vector<int> a;

int bs(int L, int R)
{
    if (L == R)
        return L;

    int mid = (L + R) / 2, res = 0;
    for (int i = 0; i < n; i++)
        res += (upper_bound(a.begin(), a.end(), a[i] + mid) - 1) - (lower_bound(a.begin(), a.end(), a[i] - mid));
    if (res / 2 >= k)
        return bs(L, mid);
    else
        return bs(mid + 1, R);
}

signed main()
{
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    cout << bs(1, 10000000000) << '\n';
}