#include <iostream>
using namespace std;
int main(){
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    b = 60 * a + b;
    d = 60 * c + d;
    if(b > d)
        d += 24 * 60;
    b = d - b;
    cout << "totally " << b / 60 << " hours and " << b % 60 << " minutes.\n";
}