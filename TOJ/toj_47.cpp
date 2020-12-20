#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll len, q, ask;
    vector<ll> list;
    cin >> len;
    for (ll i = 0; i < len; i++)
    {
        ll tmp;
        cin >> tmp;
        list.push_back(tmp);
    }
    sort(list.begin(), list.end());
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        cin >> ask;
        auto low = lower_bound(list.begin(), list.end(), ask);
        auto high = upper_bound(list.begin(), list.end(), ask);
        if (low == high)
        {
            if (low == list.begin())
            {
                cout << "no";
            }
            else
            {
                cout << *(high - 1);
            }
            cout << " ";
            if (high == list.end())
            {
                cout << "no\n";
            }
            else
            {
                cout << *high << '\n';
            }
        }
        else
        {
            cout << ask << '\n';
        }
    }
}