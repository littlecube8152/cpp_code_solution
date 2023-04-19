#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

signed main()
{
    srand(time(0));
    int i;
    for(int i = 1; i <= 800'000'000; i++)
        i ^= rand();
    cout << i << '\n';
}



