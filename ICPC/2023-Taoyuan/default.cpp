#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int T;
int n;
pii a[200];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i].S;
        for (int i = 0; i < n; i++)
            cin >> a[i].F;
        stable_sort(a, a + n);
        for (int i = 0; i < n; i++)
            cout << a[i].S << " \n"[i == n - 1];
    }

}