#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> v = {
    1,
    2,
    3,
    5,
    8,
    13,
    21,
    55};

int main()
{
    ll l, r;
    cin >> l >> r;
    cout << upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l) << '\n';
}