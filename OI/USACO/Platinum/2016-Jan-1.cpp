#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, M, ans;
int g[205][205], pre[205][205];

signed main()
{
    fast;
    ifstream cin("fortmoo.in");
    ofstream cout("fortmoo.out");
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            char c;
            cin >> c;
            g[i][j] = (c == 'X');
        }
    for (int j = 1; j <= M; j++)
        for (int i = 1; i <= N; i++)
            pre[i][j] = pre[i - 1][j] + g[i][j];
    for (int l = 1; l <= N; l++)
        for (int r = l + 1; r <= N; r++)
        {
            int last = -1;
            for (int i = 1; i <= M; i++)
                if(last == -1 && pre[r][i] - pre[l - 1][i] == 0)
                    last = i;
                else if(pre[r][i] - pre[l - 1][i] == 0)
                    ans = max(ans, (i - last + 1) * (r - l + 1));
                else if(g[l][i] || g[r][i])
                    last = -1;
        }
    cout << ans << '\n';
}