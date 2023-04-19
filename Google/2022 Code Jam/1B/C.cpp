/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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
// using namespace __gnu_pbds;

vector<string> v;

vector<string> gen(int p)
{
    if (p == 0)
        return vector<string>{"1"};
    else
    {
        vector<string> d, z, r;
        z = d = gen(p - 1);
        for (auto &s : d)
            s = s + s;
        for (auto &s : z)
            s = s + string(s.size(), '0');
        for (auto s : d)
            r.emplace_back(s);
        for (int i = 0; i < z.size(); i++)
        {
            r.emplace_back(z[i]);
            for (auto s : d)
                r.emplace_back(s);
        }
        return r;
    }
}

signed main()
{ 
    // Consider the same problem with 1-bit:
    //          1
    // When we are solving 2-bits:
    //          11
    //          10
    //          11
    // Thus we can find that in these two cases, 
    // no matter what initial position we have, we always return to 0 in some operations.
    // Then, to generalize the problem to 8-bits, let's analyze how we get the solution for 2-bits:
    //          11 = "1" doubled
    //          10 = "1" + "0"
    //          11 = "1" doubled
    // First we assume that the left half and the right half is the same, 
    // then we consider it as half bits and make the operation doubled, then we can always have the same effect.
    // If after the operations we still not getting 0s, then the left and right half aren't same.
    // Therefore, our goal is to make "left XOR right = 0", which is same as the problem with half bits.
    // The 1s correspond to the 0...1 or 1...0 and 1s correspond to 0...0 or 1...1, since the XOR arithmetic.
    // Thus, the operations in this phase is just exactly the operations with half bits but appended 0s to the end.
    // However, there's one problem is, we cannot determine when the XOR becomes 0 by the judges response,
    // Therefore, we need to use the symmentry operation to the two sides, 
    // in order to keep the XOR same and check if the left XOR right = 0.
    // It's obviously that we can use the operations we uses in the beginning, which doesn't change XOR and checks the XOR = 0.
    // Hence the problem is solved.
    fast;
    int T;
    cin >> T;
    v = gen(3);
    for (int t = 1; t <= T; t++)
    {
        int n;
        for (auto s : v)
        {
            cout << s << endl;
            cin >> n;
            if (n == 0)
                break;
        }
    }
}