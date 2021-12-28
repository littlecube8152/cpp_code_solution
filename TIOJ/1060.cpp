#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n;

unordered_map<int, int> H;

int g(int x)
{
    if (x <= 2)
        return x * x - 1;
    return 2;
}

int h(int x)
{
    return vector<int>{-1, -1, 2, 5, 5, 2}[x % 6];
}

int f(int x)
{
    if(H.find(x) != H.end())
        return H[x];
    if (x < h(x))
        return H[x] = f(g(x)) - g(x);
    else if (x > h(x))
        return H[x] = f(x - 1) - h(x);
    return 1;
}

signed main()
{
    cin >> n;
    cout << f(n) << '\n';
}
// X
// H(y) [ -1 -1 2 5 5 2 ][ -1 -1 2 5 5 2 ][ -1 -1 2 5 5 2 ][ -1 -1 2 5 5 2 ]