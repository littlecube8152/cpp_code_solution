#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
int main()
{
    int h1, m1, s1, h2, s2, m2, k1, k2;

    string s;
    stringstream ss;
    cin >> s;
    s[2] = ' ';
    s[5] = ' ';
    ss << s << " ";
    cin >> s;
    s[2] = ' ';
    s[5] = ' ';
    ss << s;
    ss >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    k1 = h1 * 3600 + m1 * 60 + s1;
    k2 = h2 * 3600 + m2 * 60 + s2;
    if (k2 < k1)
        k2 += 24 * 3600;
    cout << setw(2) << setfill('0') << (k2 - k1) / 3600 << ':' << setw(2) << setfill('0') << (k2 - k1) / 60 % 60 << ':' << setw(2) << setfill('0') << (k2 - k1) % 60 << '\n';
}