#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a, x;
    int b, y;
    cin >> a >> b >> x >> y;
    if(a == x && b ==y){
        cout << "GOOD\n";
    }
    else if (a == x || b ==y){
        cout << "=~=\n";
    }
    else{
        cout << "OTZ\n";
    }
}