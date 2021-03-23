#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    cout << "\n\nTesting for Memory in 1D Array\n";
    int array[5] = {0, 1, 2, 3, 4};

    cout << "Index |";
    for (int i = 0; i < 5; i++)
        cout << i << "         ";
    cout << "\nMemory|";
    for (int i = 0; i < 5; i++)
        cout << &array[i] << "  ";
    cout << "\nSize of \'int\' : " << sizeof(int) << "\n\n";

    cout << "\n\nTesting for Memory in 2D Array\n";
    int array2[5][3] = {{0}};
    for (int i = 0; i < 5; i++)
    {
        cout << "Index |";
        for (int j = 0; j < 3; j++)
            cout << "(" << i << ", " << j << " )"
                 << "    ";
        cout << "\nMemory|";
        for (int j = 0; j < 3; j++)
            cout << &array2[i][j] << "   ";
        cout << '\n';
    }

    cout << "\nSize of \'int\' : " << sizeof(int) << "\n\n";

    cout << "\n\nTesting for Value between a[i] and i[a]\n";
    cout << "a[i] |";
    for (int i = 0; i < 5; i++)
        cout << array[i] << "  ";
    cout << "\ni[a] |";
    for (int i = 0; i < 5; i++)
        cout << i[array] << "  ";

    cout << "\n\nTesting for Memory between a[i], i[a] and a+i\n";
    cout << "&a[i] |";
    for (int i = 0; i < 5; i++)
        cout << &array[i] << "  ";
    cout << "\n&i[a] |";
    for (int i = 0; i < 5; i++)
        cout << &i[array] << "  ";
    cout << "\na + i |";
    for (int i = 0; i < 5; i++)
        cout << (array + i) << "  ";
}