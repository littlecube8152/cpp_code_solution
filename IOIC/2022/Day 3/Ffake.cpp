#include <algorithm>
#include <iostream>
using namespace std;

int N, T;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;

        int rem = N % 14;
        if (rem == 8 || rem == 9 || rem == 13 || rem == 0 || rem == 4)
            cout << "Zweite\n";
        else

            cout << "Erste\n";
    }
}
