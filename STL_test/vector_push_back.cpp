#include <bits/stdc++.h>
using namespace std;
#define N 10000000

time_t a, b;
vector<int> arr;
signed main()
{
    srand(time(0));

    time_t a = clock();
    for (int i = 0; i < N; i++)
        arr.push_back(rand());
    double t = (clock() - a) * 1000.0 / CLOCKS_PER_SEC;
    cout << t << " ms." << '\n';
}