#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int T, N, sg[200] = {0, 1, 1, 2};

int main()
{
    for (int i = 4; i < 200; i++)
    {
        int mex[20] = {};
        mex[sg[i - 3]] = 1;
        mex[sg[i - 2]] = 1;
        for (int j = 1; j <= i - 4; j++)
        {
            int k = i - j - 3;
            mex[sg[j] ^ sg[k]] = 1;
        }
        for (int j = 0; j < 20; j++)
            if (mex[j] == 0)
            {
                sg[i] = j;
                break;
            }
    }
    cin >> T;
    while (T--)
    {
        cin >> N;
        if (N >= 100)
            N = (N - 50) % 34 + 50;
        cout << (sg[N] ? "Erste\n" : "Zweite\n");
    }
}