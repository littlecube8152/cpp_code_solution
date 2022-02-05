#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int N, win[1000005] = {0, 1, 1, 1}, pretend[1000005] = {0, 0, 0, 1};

int main()
{
    //ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 4; i <= N; i++)
    {
        if ((win[i - 2] && !pretend[i - 2]) || (win[i - 3] && !pretend[i - 3]))
            pretend[i] = 1;
        if (!win[i - 2] || !win[i - 3])
            win[i] = 1;
        for (int j = 1; j <= i - 4; j++)
        {
            int k = i - j - 3;
            if ((win[j] && pretend[j]) || (win[k] && pretend[k]))
                continue;
            else if ((win[j] && pretend[k]) || (pretend[j] && win[k]))
                pretend[i] = 1;
            else
                win[i] = 1;
        }
        int rem = i % 14;
        if (rem == 8 || rem == 9 || rem == 13 || rem == 0 || rem == 4)
        {
            if (win[i])
                cout << i << " should be lose\n";
        }
        else
        {
            if (!win[i])
                cout << i << " should be win\n";
        }
        if(i % 1000 == 0)
            cout << i << '\n';
    }
    //for (int i = 1; i <= N; i++)
    //    cout << win[i] << " |"[i % 10 == 0];
    //cout << '\n';
    //for (int i = 1; i <= N; i++)
    //    cout << pretend[i] << " |"[i % 10 == 0];
    //cout << '\n';
}
