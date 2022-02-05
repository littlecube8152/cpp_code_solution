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
//using namespace __gnu_pbds;
const int C = 1e6;
int N, L[500005], R[500005], U[500005], D[500005], seg[2000200], lazy[2000200], inorder[500005], outorder[500005];
ll ans;

void modify(int mL, int mR, int val, int i = 1, int L = 1, int R = C)
{
    int mid = (L + R) / 2;
    if (R < mL || mR < L)
        return;
    if (mL <= L && R <= mR)
    {
        lazy[i] += val;
        if (lazy[i])
            seg[i] = R - L + 1;
        else
            seg[i] = (L == R ? 0 : seg[i + 1] + seg[i + 2 * (mid - L + 1)]);
    }
    else
    {
        modify(mL, mR, val, i + 1, L, mid);
        modify(mL, mR, val, i + 2 * (mid - L + 1), mid + 1, R);
        if (lazy[i])
            seg[i] = R - L + 1;
        else
            seg[i] = (L == R ? 0 : seg[i + 1] + seg[i + 2 * (mid - L + 1)]);
    }
}

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> L[i] >> R[i] >> D[i] >> U[i];
        L[i]++, D[i]++;
        inorder[i] = outorder[i] = i;
    }
    sort(inorder + 1, inorder + 1 + N, [](int i1, int i2)
         { return D[i1] < D[i2]; });
    sort(outorder + 1, outorder + 1 + N, [](int i1, int i2)
         { return U[i1] < U[i2]; });
    for (int i = 0, udx = 1, ddx = 1; i <= C; i++)
    {
        while (ddx <= N && D[inorder[ddx]] == i)
        {
            modify(L[inorder[ddx]], R[inorder[ddx]], 1);
            ddx++;
        }
        ans += seg[1];
        while (udx <= N && U[outorder[udx]] == i)
        {
            modify(L[outorder[udx]], R[outorder[udx]], -1);
            udx++;
        }
    }
    cout << ans << '\n';
}
