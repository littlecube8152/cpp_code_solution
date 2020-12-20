#include <iostream>
using namespace std;

int main()
{
    int result = 0, count;
    cin >> count;
    for (int i = 0; i < count;i++){
        int tmp;
        cin >> tmp;
        if(tmp > result)
            result = tmp;
    }
    cout << result << '\n';
}