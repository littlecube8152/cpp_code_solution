#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string a;
    int f = 0;
    getline(cin, a);
    long long int i = 0;
    while (i < a.length())
    {
        if (a[i] != '2' && a[i] != '3' && a[i] != '5' && a[i] != '7') f += 1;
        i++;
    }
    if (f > 0)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
    }
}
