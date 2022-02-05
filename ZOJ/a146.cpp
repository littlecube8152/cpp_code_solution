/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma loop_opt(on)
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
//using namespace __gnu_pbds;

ll N, K, arr[1000005];

signed main()
{
    fast;
    while (cin >> N >> K)
    {
        K = min(K, N);
        vector<ll> amax(N + 1), amin(N + 1);
        deque<pll> qmax, qmin;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];
        for (int i = 1; i <= N; i++)
        {
            while (!qmax.empty() && arr[i] >= qmax.back().S)
                qmax.pop_back();
            qmax.push_back(pll{i, arr[i]});
            while (!qmin.empty() && arr[i] <= qmin.back().S)
                qmin.pop_back();
            qmin.push_back(pll{i, arr[i]});
            if (i >= K)
            {
                if (qmax.front().F <= i - K)
                    qmax.pop_front();
                amax[i] = qmax.front().S;
                if (qmin.front().F <= i - K)
                    qmin.pop_front();
                amin[i] = qmin.front().S;
            }
        }
        for (int i = K; i <= N; i++)
            cout << amin[i] << " \n"[i == N];
        for (int i = K; i <= N; i++)
            cout << amax[i] << " \n"[i == N];
    }
}