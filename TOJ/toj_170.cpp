#include <iostream>
#include <string>
using namespace std;
void A(int i)
{
    for (int k = 1; k <= i; k++)
    {
        cout << string((i - k), ' ');
        cout << string((2 * k - 1), '*');
        cout << endl;
    }
}

void C(int i)
{
    for (int k = 1; k <= i; k++)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << string(i - j, ' ') << string(2 * j - 1, '*') << '\n';
        }
    }
}

void D(int i)
{
    A(10 * i);
}

void E(int i)
{
    for (int k = 0; k < i; k++)
    {
        cout << string(i - k + 1, ' ') << string(2 * k + 1, '*') << '\n';
    }
    cout << string(2 * i + 3, '#') << '\n';
}

int main()
{

    int count;
    cin >> count;
    char type;
    int height;
    for (int i = 0; i < count; i++)
    {
        cin >> type >> height;
        switch (type)
        {
        case 'A':
            A(height);
            break;
        case 'B':
            A(height);
            A(height);
            break;
        case 'C':
            C(height);
            break;
        case 'D':
            D(height);
            break;
        case 'E':
            E(height);
            break;
        case 'F':
            A(2 * height);
            break;
        case 'G':
            A(3 * height);
            break;
        case 'H':
            A(7 * height);
            break;
        case 'I':
            A(4 * height - 1);
            break;
        }
        cout << "\n";
    }

}