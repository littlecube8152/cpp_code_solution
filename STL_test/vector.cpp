#include <bits/stdc++.h>
using namespace std;

time_t a, b;
vector<int> arr(1000000);
signed main()
{
    srand(time(0));

    time_t a = clock();
    for (int k = 0; k < 10; k++)
        for (int i = 0; i < 1000000; i++)
            arr[i] = rand();
    double t = (clock() - a) * 1000.0 / CLOCKS_PER_SEC;
    cout << t << " ms." << '\n';
}