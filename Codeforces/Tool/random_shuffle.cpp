#include <bits/stdc++.h>
using namespace std;

const int cnt = 26;
int vis[cnt];
signed main()
{
    mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 1; i <= cnt; i++)
    {
        int cur = rd() % cnt;
        while (vis[cur])
            cur = rd() % cnt;
        vis[cur] = 1;
        cout << (char)('A' + cur) << '\n';
    }
}