#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll merge(int l1, int r1, int l2, int r2)
{
}

ll merge_sort(int l, int r)
{
    if (l == r)
        return 0;
    int mid = (l + r) / 2;
    return merge_sort(l, mid) + merge_sort(mid + 1, r) + merge(l, mid, mid + 1, r);
}

int main()
{

    ll n, c = 0;
    set<int> s;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        c += i - (*upper_bound(s.begin(), s.end(), t));
    }
    if (n % 2 != c % 2)
        cout << "Petr";
    else
        cout << "Um_nik";
}