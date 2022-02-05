#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 2xxx or 5xxx
// xx can be 3/7
// 33 not prime => 3 cannot continue
// 77 not prime => 7 cannot continue
vector<ll> v = {2, 5, 3, 7, 23, 53, 37, 73, 373};
ll L, R;

int main()
{
    sort(v.begin(), v.end());
    cin >> L >> R;
    cout << upper_bound(v.begin(), v.end(), R) - lower_bound(v.begin(), v.end(), L) << '\n';
    
}
