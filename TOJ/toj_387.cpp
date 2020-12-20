#include <iostream>
using namespace std;

int main()
{
    float l, a, d = 0;
    cin >>a >>l ;
    l *= l;
    while(l > a){
        l /= 2;
        d++;
    }
    cout << d << '\n';
}