#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    for (int i = 1; i <= a; i ++){
        cout << string(i-1, ' ') << string(2*a-2*i + 1, char(a +1-i + 64)) << '\n';
    }
}