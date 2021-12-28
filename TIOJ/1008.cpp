//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, a[6], t;
map<int, bool> vis;
clock_t T = clock();
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> t;
    queue<vector<int>> q;
    q.push(vector<int>{0, 0, 0, 0, 0, 0});
    while (!q.empty() && clock() - T < CLOCKS_PER_SEC * 1.5)
    {
        vector<int> v = q.front();
        if (vis[v[1] + v[2] * 51 + v[3] * 51 * 51 + v[4] * 51 * 51 * 51 + v[5] * 51 * 51 * 51 * 51])
        {
            q.pop();
            continue;
        }
        vis[v[1] + v[2] * 51 + v[3] * 51 * 51 + v[4] * 51 * 51 * 51 + v[5] * 51 * 51 * 51 * 51] = 1;
        //printf("DFS %d %d %d %d %d %d\n", v[0], v[1], v[2], v[3], v[4], v[5]);

        for (int i = 1; i <= n; i++)
            if (v[i] == t)
            {
                cout << v[0] << '\n';
                return 0;
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j)
                    if (v[j] < a[j])
                    {
                        vector<int> u = v;
                        if (v[i] + v[j] > a[j])
                        {
                            u[j] = a[j], u[i] = v[i] - (a[j] - v[j]), u[0] = v[0] + 1;
                            q.push(u);
                        }
                        u[j] = min(v[i] + v[j], a[j]), u[i] = 0, u[0] = v[0] + 1;
                        q.push(u);
                    }
        for (int i = 1; i <= n; i++)
            if (v[i] > 0)
            {
                vector<int> u = v;
                u[i] = 0, u[0] = v[0] + 1;
                q.push(u);
            }
        for (int i = 1; i <= n; i++)
            if (v[i] < a[i])
            {
                vector<int> u = v;
                u[i] = a[i], u[0] = v[0] + 1;
                q.push(u);
            }
        q.pop();
    }
    cout << -1 << '\n';
}