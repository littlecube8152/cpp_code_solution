#include <bits/stdc++.h>
#include "lib1617.h"
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n;

signed main()
{
    n = Get_Box();
    if (n == 1)
        Report(1);
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++)
    {
        int k = Med3(a, b, i);
        if (k == a)
            a = i;
        if (k == b)
            b = i;
    }
    vector<int> v;
    for (int i = 1; i <= n; i++)
        if(i != a && i != b)
            v.emplace_back(i);
    
    nth_element(v.begin(), v.begin() + (n / 2) - 1, v.end(), [=](int i, int j) {if(Med3(i, j, a) == j)return 1; return 0; });
    Report(v[(n / 2) - 1]);
}