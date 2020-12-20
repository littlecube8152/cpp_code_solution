#include <iostream>
using namespace std;
int main()
{
    int a ,b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= b; i++){
        int m, n;
        cin >> m >> n;
        m *= n;
        a += m;
    }
    a -= c;
    a /= 4;
    cout << a << '\n';

}