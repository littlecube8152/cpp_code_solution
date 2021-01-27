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
    string sp, sq;
    getline(cin, sp);
    getline(cin, sq);
    for (int i = min(sp.length(), sq.length()); i >= 0; i--)
    {
        if (sp.substr(0, 0 + i) == sq.substr(sq.length() - i, sq.length()))
        {
            cout << i << '\n';
            return 0;
        }
    }
}