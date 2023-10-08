#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int stoint(string s)
{
    stringstream ss;
    int i;
    ss << s;
    ss >> i;
    return i;
}

signed main()
{
    int n, k, m, sum = 0;
    cin >> n >> k;
    vector<int> v;
    for (int i = 1; i <= k; i++)
    {
        string s;
        cin >> s;
        if (s == "undo")
        {
            cin >> m;
            while (m--)
                v.pop_back();
        }
        else
            v.emplace_back(stoint(s));
    }
    for (auto i : v)
        sum += i;
    cout << (sum % n + n) % n << '\n';
}