#include <bits/stdc++.h>
using namespace std;
#define N 10000000

time_t a, b;
vector<int> arr(N);
signed main()
{
    srand(time(0));
    for (int i = 0; i < N; i++)
        arr[i] = rand();

    time_t a = clock();
    arr.clear();
    double t = (clock() - a) * 1000.0 / CLOCKS_PER_SEC;
    cout << t << " ms." << '\n';
}