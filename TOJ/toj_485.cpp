#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string a;
    bool enchant = false;
    int shift = 0;
    cin >> a >> a;
    string opposite = a;
    for (int i = 0; i < a.length(); i++)
    {
        opposite[i] = a[a.length() - i - 1];
    }
    for (shift = 0; shift < a.length(); shift++)
    {
        for (int j = 0; j < a.length() - shift; j++)
        {
            if (opposite[j] != a[j + shift])
            {
                break;
            }
            else if (j == a.length() - shift - 1)
            {
                enchant = true;
            }
        }
        if (enchant == true)
        {
            break;
        }
    }
    cout << shift << '\n';
}
