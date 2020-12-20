#include <iostream>
using namespace std;

int main()
{
    int a[20], count;
    cin >> count;
    for (int i = 0; i < count; i++){
        cin >> a[i];
    }
    for (int i = count - 1; i >= 0; i--){
        cout << a[i] << '\n';
    }
}