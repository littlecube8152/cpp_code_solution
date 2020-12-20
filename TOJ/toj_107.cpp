#include <iostream>
using namespace std;
int main()
{
    int result = 0;
    for (int i = 1; i <= 30; i++){
        result += 1;
        result += i;
        result += (i * i * (i + 1) / 2);
    }
    cout << result << endl;
}