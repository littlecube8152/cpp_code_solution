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

ll N, L, H[100005], W[100005], dp[100005], seg[200005], lazy[200005];

void modify(int mL, int mR, ll val, int i = 1, int L = 1, int R = N)
{
    if (mL <= L && R <= mR)
        lazy[i] += val;
    else if (mR < L || R < mL)
        return;
    else
    {
        int mid = (L + R) >> 1;
        lazy[i + 1] += lazy[i];
        lazy[i + 2 * (mid - L + 1)] += lazy[i];
        lazy[i] = 0;
        modify(mL, mR, val, i + 1, L, mid);
        modify(mL, mR, val, i + 2 * (mid - L + 1), mid + 1, R);
        seg[i] = min(seg[i + 1] + lazy[i + 1], seg[i + 2 * (mid - L + 1)] + lazy[i + 2 * (mid - L + 1)]);
    }
}

ll query(int qL, int qR, int i = 1, int L = 1, int R = N)
{
    if (qL <= L && R <= qR)
        return lazy[i] + seg[i];
    else if (qR < L || R < qL)
        return 1e15;
    else
    {
        int mid = (L + R) >> 1;
        return lazy[i] + min(query(qL, qR, i + 1, L, mid), query(qL, qR, i + 2 * (mid - L + 1), mid + 1, R));
    }
}

signed main()
{
    cin >> N >> L;
    for (int i = 1; i <= N; i++)
        cin >> H[i] >> W[i];
    H[0] = 1e15;
    ll ldx = 1, acc = 0;
    deque<int> dq;
    dq.push_front(0);
    for (int i = 1; i <= N; i++)
    {
        acc += W[i];

        while (acc > L)
        {
            acc -= W[ldx];
            ldx++;
        }
        modify(i, i, H[i]);
        while (H[dq[0]] < H[i])
        {
            modify(dq[1] + 1, dq[0], H[i] - H[dq[0]]);
            dq.pop_front();
        }
        dq.push_front(i);

        dp[i] = query(ldx, i);
        modify(i + 1, i + 1, dp[i]);
    }

    cout << dp[N] << '\n';
}