#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    vector<int> a, b;

    cin >> n;
    a.resize(n), b.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    auto iter = unique(b.begin(), b.end());
    b.resize(iter - b.begin());
    for (int i = 0; i < n; i++)
        a[i] = (lower_bound(b.begin(), b.end(), a[i]) - b.begin());

    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];
}