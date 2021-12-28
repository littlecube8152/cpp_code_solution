#include <bits/stdc++.h>
#define ll __int128_t
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string s;
ll answer = 0, a[60];
long long D;
int chartoint(char c)
{
    if ('A' <= c && c <= 'Z')
        return c - 'A' + 1;
    if ('a' <= c && c <= 'z')
        return c - 'a' + 27;
    return 0;
}

signed main()
{
    cin >> D >> s;
    for (int i = 0; i < s.length(); i++)
        a[chartoint(s[i])]++;

    for (int i = 0; i < s.length(); i++)
    {
        vector<ll> divide;
        long double res = 0;
        for (int j = 1; j < chartoint(s[i]); j++)

            res += a[j];
        for (int j = 1; j < 60; j++)
            for (ll k = 2; k <= a[j]; k++)
                divide.emplace_back(k);
        sort(divide.begin(), divide.end(), [](ll a, ll b) { return a < b; });
        for (int j = s.length() - i - 1; j >= 2; j--)
        {
            res *= j;
            while (!divide.empty() && (res > 100000000.0 || (ll)res % divide.back() == 0))
            {
                res /= divide.back();
                divide.pop_back();
            }
            if (divide.empty())
                res = (ll)res % D;
        }
        while (!divide.empty())
        {
            res /= divide.back();
            divide.pop_back();
        }
        res = (ll)res % D;
        a[chartoint(s[i])]--;
        answer = (answer + (ll)res) % D;
    }
    cout << (long long)(answer) << '\n';
}