#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

map<string, int> mp;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int N, K;
    string s;
    cin >> N >> K;
    getline(cin, s);
    for(int i = 1; i <= 3 * N; i++)
    {
        getline(cin, s);
        mp[s] -= mp[s] % 1000000;
        mp[s] += 1000000 + i;
    }
    vector<pair<int ,string>> v;
    for(auto [s, i] : mp)
        v.emplace_back(make_pair(i, s));
    sort(v.begin(), v.end(), greater<>());
    for(int i = 0; i < min((int)v.size(), K); i++)
        cout << v[i].S << '\n';
}


