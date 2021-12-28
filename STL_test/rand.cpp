#include <bits/stdc++.h>
using namespace std;
#define N 10000

time_t a, b;
deque<int> dq;

signed main()
{

    
    int k = 0;
    std::mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
    

    time_t a = clock();

    k ^= rd() % N;

    double t = (clock() - a) * 1000.0 / CLOCKS_PER_SEC;
    cout << t << " ms." << '\n';
}
