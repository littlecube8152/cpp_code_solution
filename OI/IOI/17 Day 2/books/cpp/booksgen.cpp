#pragma GCC optimize("Ofast,unroll-loops")
#include "books.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

signed main()
{
    int n = 8;
    mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
    int s = rd() % n;
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.emplace_back(i);
    shuffle(v.begin(), v.end(), rd);
    cout << n << ' ' << s << '\n';
    for (int i = 0; i < n; i++)
        cout << v[i] << " \n"[i == n - 1];
    cerr << n << ' ' << s << '\n';
    for (int i = 0; i < n; i++)
        cerr << v[i] << " \n"[i == n - 1];
}