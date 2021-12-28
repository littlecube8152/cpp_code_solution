//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> p = {2};
int n, k;
vector<int> v;

signed main()
{
    fast;
    for (int i = 3; i < 100005; i += 2)
    {
        bool b = 1;
        int sq = ceil(sqrt(i));
        for (int j : p)
            if (j > sq)
                break;
            else if (!(i % j))
            {
                b = 0;
                break;
            }
        if (b)
            p.emplace_back(i);
    }
    cin >> n >> k;
    for (int i : p)
        while (n % i == 0)
            if (v.size() == k)
                break;
            else
                v.emplace_back(i), n /= i;
    if (v.size() == k)
    {
        v.back() *= n;
        for (int i : v)
            cout << i << " ";
    }
    else
        cout << -1;
}