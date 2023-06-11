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
    ll a, b, c, suma = 0, sumb = 0, sumc = 0, mina = _INFINITY, minb = _INFINITY, minc = _INFINITY, r = 0;
    cin >> a >> b >> c;
    for (int i = 0; i < a; i++)
    {
        ll tmp;
        cin >> tmp;
        suma += tmp;
        mina = min(mina, tmp);
    }
    for (int i = 0; i < b; i++)
    {
        ll tmp;
        cin >> tmp;
        sumb += tmp;
        minb = min(minb, tmp);
    }
    for (int i = 0; i < c; i++)
    {
        ll tmp;
        cin >> tmp;
        sumc += tmp;
        minc = min(minc, tmp);
    }
    if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1))
        cout << max((suma - sumb - sumc), max((-suma + sumb - sumc), (-suma - sumb + sumc)));
    else if (a == 1 || b == 1 || c == 1)
        cout << max((suma + sumb - sumc), max((-suma + sumb + sumc), (suma - sumb + sumc)));
    else
        cout << max(max((suma + sumb - sumc - minb * 2 - minc * 2), max((suma + sumb + sumc - mina * 2 - minc * 2), (suma + sumb + sumc - minb * 2 - mina * 2))),max((suma + sumb - sumc), max((-suma + sumb + sumc), (suma - sumb + sumc))));
}