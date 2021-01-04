#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

struct Friend
{
    ll w = 0;
    ll h = 0;
    ll id;
};
bool comp(Friend f1, Friend f2)
{
    if (f1.w != f2.w)
        return f1.w < f2.w;
    if (f1.h != f2.h)
        return f1.h < f2.h;
    return 1;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        vector<Friend> v, sortedv;
        vector<int> r(200005, -1);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int w, h;
            Friend f;
            cin >> w >> h;
            f.w = w;
            f.h = h;
            f.id = i + 1;
            v.emplace_back(f);
        }
        sort(v.begin(), v.end(), comp);
        for (auto f : v)
            for (auto j : v)
                if (r[j.id] == -1)
                    if ((f.w < j.w && f.h < j.h) || (f.h < j.w && f.w < j.h))
                        r[j.id] = f.id;

        for (int i = 1; i <= n; i++)
            cout << r[i] << " \n"[i == n];
    }
}