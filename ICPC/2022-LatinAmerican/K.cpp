#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

const int C = 100;
int K;
vector<pii> F;
vector<pii> sol[100];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> K;
    if (K == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    else
    {
        int T = __lg(K - 1) + 1;
        K--;
        int cur = 0;
        for (int i = 1; i <= C; i++)
            for (int j = 1; j <= C; j++)
                if (i == 1 || j % 2 == 1)
                    for (int k = 0; k < T; k++)
                        sol[k].emplace_back(i, j);
                else
                {
                    if (cur < K)
                    {
                        for (int k = 0; k < T; k++)
                            if ((cur >> k) & 1)
                                sol[k].emplace_back(i, j);
                        cur++;
                    }
                }
        cout << T << '\n';
        for (int i = 0; i < T; i++)
        {
            cout << sol[i].size();
            for (auto [x, y] : sol[i])
                cout << ' ' << x << ' ' << y;
            cout << '\n';
        }
    }
}