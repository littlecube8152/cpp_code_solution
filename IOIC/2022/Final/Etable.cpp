#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
int sg[1005][1005];

void calc(int i, int j)
{
    int mex[1005] = {0};
    for (int k = 1; k < i; k++)
    {
        int l = i - k;
        assert(l > 0);
        mex[sg[k][l]] = 1;
    }
    for (int k = 1; k < j; k++)
    {
        int l = j - k;
        assert(l > 0);
        mex[sg[k][l]] = 1;
    }
    for (int res = 0; res <= 1005; res++)
    {
        if (!mex[res])
        {
            sg[i][j] = res;
            break;
        }
    }
}

int main()
{
    cin >> N;
    sg[0][0] = sg[1][0] = sg[0][1] = sg[1][1] = 0;
    for (int sum = 1; sum <= N; sum++)
    {
        for (int i = 1; i < sum; i++)
            calc(i, sum - i);
        calc(sum, 0);
        calc(0, sum);
    }
    for (int i = 0; i <= N / 2; i++)
        for (int j = 0; j <= N / 2; j++)
            cout << sg[i][j] << " \n"[j == N / 2];
}