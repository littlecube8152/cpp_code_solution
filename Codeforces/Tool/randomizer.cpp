#include <bits/stdc++.h>
using namespace std;

const int mxRound = 1644, cnt = 26;
signed main()
{
    mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 1; i <= cnt; i++)
        cout << i << (i <= 26 ? (char)('A' + i - 1) : ' ') << " " << rd() % mxRound + 1 << '\n';
}