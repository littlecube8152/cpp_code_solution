#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll a[500], b[500], dots, rotation = 1, result = 0;
    cin >> dots;
    for (int i = 0; i < dots; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < dots; i++)
    {
        for (int j = 0; j < dots; j++)
        {
            if (a[i] == b[j] && j != i)
            {
                if ((j - i) / abs(j - i) != rotation)
                {
                    result++;
                    rotation = -rotation;
                }
            }
        }
    }
    cout << result << '\n';
}
