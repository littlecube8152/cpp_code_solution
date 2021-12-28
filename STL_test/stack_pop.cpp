#include <bits/stdc++.h>
using namespace std;
#define N 10000000

time_t a, b;
stack<int> st;

signed main()
{
    srand(time(0));
    for (int i = 0; i < N; i++)
        st.push(rand());
    time_t a = clock();
    for (int i = 0; i < N; i++)
        st.pop();
    double t = (clock() - a) * 1000.0 / CLOCKS_PER_SEC;
    cout << t << " ms." << '\n';
}