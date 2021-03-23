#include <bits/stdc++.h>
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
map<int, int> mp;
vector<pii> v;
signed main()
{
    cin >> n;
    for (int i = 2; i <= sqrt(n);i++)
        while(!(n % i))
            mp[i]++, n /= i;
    if(n != 1)
        mp[n]++;
    for (auto i : mp)
        v.emplace_back(i);
    for (int i = 0; i < v.size();i++)
        if(v[i].second == 1)
            cout << v[i].first << (i == v.size() - 1 ? "\n" : " * ");
        else 
            cout << v[i].first << "^" << v[i].second << (i == v.size() - 1 ? "\n" : " * ");
}