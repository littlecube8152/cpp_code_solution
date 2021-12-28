#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int a[100005];
bool b[100005] = {0};
vector<ll> v;

int main()
{
    fast;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if(b[i])
            continue;
        int k = a[i], r = 1;
        b[i] = 1;
        while(k != i)
        {
            b[k] = 1;
            k = a[k];
            r++;
        }
        v.emplace_back(r);
    }
    sort(v.begin(), v.end());
    if(v.size()>=2)
    {
        v[v.size() - 2] += v[v.size() - 1];
        v[v.size() - 1] = 0;
    }
    ll res = 0;
    for(ll i : v)
        res += i * i;
    cout << res;
}