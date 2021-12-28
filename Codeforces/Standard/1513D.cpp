/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
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

int t, n, dsu[200005], sparse[25][200005], order[200005], ans, p;

int find(int k)
{
    return k == dsu[k] ? k : k = find(dsu[k]);
}

signed main()
{
    //fast;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        ans = (n - 1) * p;
        for (int i = 1; i <= n; i++)
            dsu[i] = order[i] = i;
        for (int i = 1; i <= n; i++)
            cin >> sparse[0][i];
        for (int i = 1; i <= __lg(n) + 1; i++)
            for (int j = 1; j <= n; j++)
                sparse[i][j] = __gcd(sparse[i - 1][j], sparse[i - 1][min(n, j + (1 << (i - 1)))]);

        sort(order + 1, order + n + 1, [](int a, int b) { if(sparse[0][a] != sparse[0][b]) return sparse[0][a] < sparse[0][b]; return a < b; });
        for (int i = 1; i <= n; i++)
        {
            if (sparse[0][order[i]] >= p)
                break;
            if (order[i] == n)
                continue;
            int l = order[i], r = n;
            while (l < r)
            {
                int mid = (l + r + 1) / 2;
                if (__gcd(sparse[__lg(mid - order[i] + 1)][order[i]],
                          sparse[__lg(mid - order[i] + 1)][mid - (1 << __lg(mid - order[i])) + 1]) == sparse[0][order[i]])
                    l = mid;
                else
                    r = mid - 1;
            }
            if (r != l)
                continue;
            //cout << "has edge: " << order[i] << " " << r << '\n';
            if (find(r) == find(order[i]))
                continue;
            for (int j = r; j > order[i]; j--)
            {

                //cout << "build: " << order[i] << " " << j << '\n';
                dsu[find(j)] = find(order[i]);
                ans -= (p - sparse[0][order[i]]);
            }
        }
        cout << max(0LL, ans) << '\n';
    }
}