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
//using namespace __gnu_pbds;
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

const ll mxN = 1000000009;
int M, K;
vector<__int8> dp;
bitset<1000000010> b;

ll inv(ll a, ll &iter)
{
    iter++;
    if (a == 1)
        return 1;
    return (M - (M / a)) * inv(M % a, iter) % M;
}

signed main()
{

    ofstream cout("test.txt");

    cout << "Tester Version v0.2b" << endl;

    for (int i = 4; i <= mxN; i += 2)
        b[i] = 1;
    b[0] = b[1] = 1;

    cout << "Prime Sieve... ";

    for (int i = 3; i <= mxN; i += 2)
        if (!b[i])
            for (int j = i * i; j <= mxN; j += i)
                b[j] = 1;

    cout << "[Comlplete]\n";

    for (int i = 2; i <= mxN; i++)
        if (!b[i])
        {
            cout << "Checking Prime " << i << ", ";
            M = i;
            dp.clear();
            dp.emplace_back(0);
            dp.emplace_back(1);

            int mxiter = 1;
            vector<int> v = {1};
            for (int j = 2; j < i; j++)
            {
                dp.emplace_back(dp[M % j] + 1);
                if (dp[j] > mxiter)
                {
                    mxiter = dp[j];
                    v.clear();
                    v.emplace_back(j);
                }
                else if (dp[j] == mxiter)
                    v.emplace_back(j);
            }
            cout << "Worst iter: " << mxiter << ", ";
            cout << "Worst case: ";
            for (int i = 0; i < v.size() - 1; i++)
                cout << v[i] << ", ";
            cout << v.back() << endl;
            std::cout << "Checked " << i << "\n";
            if (mxiter >= 50)
            {
                cout << "!!! Warning, may be worst case !!!" << endl;
                std::cout << "!!! Warning, may be worst case !!!" << endl;
            }
        }
}
