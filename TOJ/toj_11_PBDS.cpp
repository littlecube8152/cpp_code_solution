#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC comment(linker,"/stack:200000000")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;

tree<int,                               //Data Type (Key)
     null_type,                         //Value (null_type -> set)
     greater_equal<int>,                         //Key Compare Function
     rb_tree_tag,                       //Data Structure
     tree_order_statistics_node_update> //Policy of Updating Invariant> 
    ordered_set;
//  *Runtime will WORSE than Segment tree

ll n, ans;
signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        int x;
        cin >> x;
        ans += ordered_set.order_of_key(x);
        ordered_set.insert(x);
    }
    cout << ans << '\n';
}