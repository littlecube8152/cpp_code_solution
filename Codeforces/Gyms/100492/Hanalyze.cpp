/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define pii128 pair<__int128, __int128>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
//using namespace __gnu_pbds;

const __int128 limit = (__int128)10000000000 * (__int128)10000000000 * (__int128)10000000;
__int128 prime[31] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};

void brute(int pre, int last, pii128 prod, vector<pii128> &v)
{
    if (pre > last)
        v.emplace_back(prod);
    else
    {
        if (prod.F * prime[pre] <= limit)
            brute(pre + 1, last, {prod.F * prime[pre], prod.S}, v);
        if (prod.S * prime[pre] <= limit)
            brute(pre + 1, last, {prod.F, prod.S * prime[pre]}, v);
    }
}

signed main()
{
    fast;
    int t = 0, n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<pii128> left, right;
        __int128 ans = 0;
        brute(1, n / 2, {1, 1}, left);
        brute(n / 2 + 1, n, {1, 1}, right);
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        for (int i = 0; i < left.size(); i++)
        {
            int L = 0, R = right.size();
            while (L < R)
            {
                int mid = (L + R + 1) / 2;
                if (double(left[i].F) * double(right[mid].F) > 1e27)
                    R = mid - 1;
                else if (double(left[i].S) * double(right[mid].S) > 1e27)
                    L = mid;
                else if (left[i].F * right[mid].F > left[i].S * right[mid].S)
                    R = mid - 1;
                else
                    L = mid;
            }
            for (int j = max(0, L - 1); j <= min(L + 1, (int)right.size()); j++)
                ans = max(ans, min(left[i].F * right[j].F, left[i].S * right[j].S));
        }
        cout << "Case #" << ++t << ": ";
        for (int i = 1; i <= n; i++)
            if (ans % prime[i] == 0)
                cout << (int)prime[i] << " ";
        cout << '\n';
    }
}
