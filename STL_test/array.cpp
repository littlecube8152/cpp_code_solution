#include <bits/stdc++.h>
using namespace std;
#define N 10000000

time_t a, b;
int arr[N];
signed main()
{
    srand(time(0));

    time_t a = clock();
    for (int i = 0; i < N; i++)
        arr[i] = rand();
    double t = (clock() - a) * 1000.0 / CLOCKS_PER_SEC;
    cout << t << " ms." << '\n';
}