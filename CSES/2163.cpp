/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;

#define LOCAL

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll n, k, f[200005], bit[2000005];
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;
signed main()
{
    //fast;
    /*
    Let f(n, k) denotes the survivor when the number of the people is n and kill every k-th
    When one's killed, the n decreases by 1 and the cycle shifts by k:
    
    e.g. n = 7, k = 3
    (0)  1  -2-  3   4   5   6  --- f(n, k)
     0   1      (2)  3  -4-  5  --- f(n - 1, k) and shifts by k - 1
     4   5       0   1  -2-  3  --- f(n - 1, k)
                                
    => f(n, k) = p + k   mod n

    And the base case is f(1, k) = 0.
    */
    cin >> n >> k;
    //k += 1;

    for (int i = 1; i <= n; i++)
        st.insert(i);
    for (int i = n, old = 0; i >= 1; i--)
    {
        int idx = *st.find_by_order((old + k) % i);
        cout << idx << " ";
        st.erase(st.find_by_order((old + k) % i));
        old = (old + k + i) % i;
    }
}
