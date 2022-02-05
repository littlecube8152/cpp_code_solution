#include <bits/stdc++.h>
using namespace std;
#define N 10000000

time_t a, b;
deque<int> dq[N];

signed main()
{
    std::mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < N; i++)
        dq[i].push_back(rd() % N);

    time_t a = clock();

    for (int i = 0; i < N; i++)
        dq[i].back() = (rd() % N);

    double t = (clock() - a) * 1000.0 / CLOCKS_PER_SEC;
    cout << t << " ms." << '\n';
}