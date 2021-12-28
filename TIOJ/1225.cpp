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

ll T, N, M;
pii lnk[2000005];

void solve()
{
    int idx = 0, ans = 0, first;
    vector<int> v;
    cin >> N >> M >> first;
    lnk[first] = {0, 0};
    lnk[0] = {first, first};
    while (M--)
    {
        int K, A, B, C;
        cin >> K >> A >> B >> C;
        if (K == 1 && C == 1)
        {
            lnk[A] = {lnk[B].F, B};
            lnk[lnk[B].F].S = A;
            lnk[B].F = A;
        }
        else if (K == 1 && C == 2)
        {
            lnk[A] = {B, lnk[B].S};
            lnk[lnk[B].S].F = A;
            lnk[B].S = A;
        }
        else if (K == 2 && A == B)
        {
            lnk[lnk[A].F].S = lnk[A].S;
            lnk[lnk[A].S].F = lnk[A].F;
            lnk[A].F = lnk[C].F;
            lnk[A].S = C;
            lnk[lnk[C].F].S = A;
            lnk[C].F = A;
        }
        else if (K == 2)
        {
            lnk[lnk[A].F].S = lnk[B].S;
            lnk[lnk[B].S].F = lnk[A].F;
            lnk[A].F = lnk[C].F;
            lnk[B].S = C;
            lnk[lnk[C].F].S = A;
            lnk[C].F = B;
        }
        else if (K == 3 && C == 1)
        {
            int send = A;
            while (B && send != 0)
            {
                B--;
                v.pb(send);
                lnk[lnk[send].F].S = lnk[send].S;
                lnk[lnk[send].S].F = lnk[send].F;
                send = lnk[send].F;
            }

            ans += B;
        }
        else if (K == 3 && C == 2)
        {
            int send = A;
            while (B && send != 0)
            {
                B--;
                v.pb(send);
                if (lnk[send].F != 0)
                    lnk[lnk[send].F].S = lnk[send].S;
                if (lnk[send].S != 0)
                    lnk[lnk[send].S].F = lnk[send].F;
                send = lnk[send].S;
            }
            ans += B;
        }
        //for (int i = 1; i <= N; i++)
        //    cout << "(" << lnk[i].F << ", " << lnk[i].S << ") "
        //         << " \n"[i == N];
    }

    cout << ans << '\n';
    for (int i : v)
        cout << i << '\n';
}

signed main()
{
    fast;
    cin >> T;
    while (T--)
        solve();
}