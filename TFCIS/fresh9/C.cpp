#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

int N;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while(N--)
    {
        long long x;
        cin >> x;
        cout << x + x % 2 << " ";
    }
}