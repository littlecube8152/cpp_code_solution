#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<pll> v;
bool comp(pll p1, pll p2)
{
    if (p2.first * p1.second != p1.first * p2.second)
        return p2.first * p1.second > p1.first * p2.second;
    else
        return p1.first < p2.first;
}

int main()
{

    ll n, r = 0, sumw = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(make_pair(x, 0));
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i].second = x;
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < n; i++)
    {
        r += sumw * v[i].second;
        sumw += v[i].first;
    }
    cout << r << '\n';
}