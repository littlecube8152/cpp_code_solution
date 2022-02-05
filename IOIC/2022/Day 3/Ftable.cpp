#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int N, sg[1000005] = {0, 1, 1, 2};

int main()
{
    cin >> N;
    for (int i = 4; i <= N; i++)
    {
        int mex[100005] = {};
        mex[sg[i - 3]] = 1;
        mex[sg[i - 2]] = 1;
        for (int j = 1; j <= i - 4; j++)
        {
            int k = i - j - 3;
            mex[sg[j] ^ sg[k]] = 1;
        }
        for (int j = 0; j <= i; j++)
            if(mex[j] == 0)
            {
                sg[i] = j;
                break;
            }
    }
    for (int i = 1; i <= N; i++)
        cout << sg[i] << " \n"[i % 34 == 0];
    cout << '\n';
}
