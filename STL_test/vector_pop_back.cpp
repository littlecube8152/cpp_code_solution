#include <bits/stdc++.h>
using namespace std;

time_t a, b;
vector<int> arr[10];
signed main()
{
    srand(time(0));

    for (int k = 0; k < 10; k++)
        for (int i = 0; i < 1000000; i++)
            arr[k].push_back(rand());

    time_t a = clock();
    for (int k = 0; k < 10; k++)
        for (int i = 0; i < 1000000; i++)
            arr[k].pop_back();
    double t = (clock() - a) * 1000.0 / CLOCKS_PER_SEC;
    cout << t << " ms." << '\n';
}