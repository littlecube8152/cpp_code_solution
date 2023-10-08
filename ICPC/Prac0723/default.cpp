#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

signed main()
{
    int n;
    string s;
    cin >> s;
    n = s.size();
    string a(s.begin(), s.begin() + n / 2), b(s.begin() + n / 2, s.end());
    int A = 0, B = 0;
    for (auto c : a)
        A += c - 'A';
    for (auto c : b)
        B += c - 'A';
    for (auto &c : a)
    {
        int d = c - 'A';
        c = 'A' + (d + A) % 26;
    }
    for (auto &c : b)
    {
        int d = c - 'A';
        c = 'A' + (d + B) % 26;
    }
    for (int i = 0; i < n / 2; i++)
    {
        int d = (a[i] - 'A') + (b[i] - 'A');
        cout << char('A' + d % 26);
    }
    cout << '\n';
}