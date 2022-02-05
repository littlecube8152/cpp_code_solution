#include <bits/stdc++.h>
using namespace std;
#define N 10000000

time_t a, b;
stack<int> st;

signed main()
{
    srand(time(0));
        int res = 0;
    time_t a = clock();
    for (int i = 0; i < N; i++)
        st.push(rand());
    for (int i = 0; i < N; i++)
    {
        res ^= st.top();
        st.pop();
    }

    double t = (clock() - a) * 1000.0 / CLOCKS_PER_SEC;

    a = clock();
    for (int i = 0; i < N; i++)
        st.push(rand());
    for (int i = 0; i < N; i++)
    {
        res ^= 1;
        st.pop();
    }

    double t2 = (clock() - a) * 1000.0 / CLOCKS_PER_SEC;
    cout << t - t2 << " ms." << '\n';
}