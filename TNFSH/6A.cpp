#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= n;j++)
            if(j == n)
                cout << '*' << '\n';
                else if(j >= i)
                    cout << '*';
                    else
                        cout << ' ';
}