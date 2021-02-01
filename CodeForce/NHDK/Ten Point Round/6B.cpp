#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    cout << "Drink " << (n >= 90 ? "Yes" : "No") << "\n";
    cout << "Cookie " << (n >= 80 ? "Yes" : "No") << "\n";
    cout << "Stationery " << (n >= 70 ? "Yes" : "No") << "\n";
    cout << "Water " << (n >= 60 ? "Yes" : "No") << "\n";
}