#include <iostream>
using namespace std;

int main()
{
    int y, m, d;
    string dn, re;
    cin >> y >> m >> d >> dn >> re;
    cout << y + 1997 << "/" << m << '/' << d << '\n'
         << "Doodle Name: " << dn << "\nReviews: " << re << '\n';
}