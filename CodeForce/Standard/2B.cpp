#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

pair<int, int> matrix[1001][1001], dp[1001][1001];

int main()
{
    int n, number;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 0; j++)
        {
            cin >> number;
            while (number % 2 == 0)
            {
                number /= 2;
                matrix[i][j].first++;
            }
            while (number % 5 == 0)
            {
                number /= 5;
                matrix[i][j].second++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 0; j++)
        {
            if (i == 0 && j == 0)
            {

            }
            else if (i == 0)
            {
            }
            else if (j == 0)
            {
            }
            else
            {
            }
        }
    }
}
