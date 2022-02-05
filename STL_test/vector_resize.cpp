#include <bits/stdc++.h>
using namespace std;
#define N 1000000

time_t a, b;
vector<int> arr;
signed main()
{
    srand(time(0));

    time_t a = clock();
    arr.resize(N);
    double t = (clock() - a) * 1000.0 / CLOCKS_PER_SEC;
    cout << t << " ms." << '\n';
}