#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    string sa, sb;
    stringstream ssa, ssb;
    long double a, b;
    cin >> sa >> sb;
    ssa << sa;
    ssb << sb;
    ssa >> a;
    ssb >> b;
    if(a > b){
        cout << sa << '\n';
    }
    else
        cout << sb << '\n';
}