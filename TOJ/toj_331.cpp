#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string a;
    long long int f = 0;
    long long int s = 0;
    getline(cin, a);
    long long int i = 0;
    while (a[i] != ' ')
    {
        if (a[i] != '0') f += 1;
        i++;
    }
    i++;
    while (i < a.length())
    {
        if (a[i] != '0') s += 1;
        i++;
    }
    cout << f*s << '\n';
}
