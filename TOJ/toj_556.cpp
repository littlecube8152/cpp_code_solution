#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

ll work, part, money, works[100005], paid[100005], max_time = 0;

ll binary_search(ll mmax, ll min)
{
    ll tmp_money = money;
    if (mmax - min <= 1)
    {
        for (ll i = 0; i < work; i++)
            tmp_money -= (max(0LL, part - (min * works[i])) + paid[i] - 1) / paid[i];
        if (tmp_money < 0)
            return mmax;
        else
            return min;
    }
    else
    {
        ll mid = (mmax + min) / 2;

        for (ll i = 0; i < work; i++){
            
            tmp_money -= (max(0LL, part - (mid * works[i])) + paid[i] - 1) / paid[i];
        }
        if (tmp_money < 0)
            return binary_search(mmax, mid + 1);
        else
            return binary_search(mid, min);
    }
}

int main()
{

    cin >> work >> part >> money;
    for (long long int i = 0; i < work; i++)
    {
        cin >> works[i];
        max_time = max(max_time, (part + works[i] - 1) / works[i]);
    }
    for (long long int i = 0; i < work; i++)
        cin >> paid[i];

    cout << binary_search(max_time, 0) << "\n";
}