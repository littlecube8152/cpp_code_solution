#include <iostream>
using namespace std;

int main()
{
    string str[10] = {"EMPTY", "EMPTY", "EMPTY", "EMPTY", "EMPTY", "EMPTY", "EMPTY", "EMPTY", "EMPTY", "EMPTY"};
    int count;
    cin >> count;
    for (int i = 0; i < count;i++){
        int loc;
        string name;
        cin >> name >> loc;
        str[loc - 1] = name;
    }
        for (int i = 0; i < 10;i++){
        cout << str[i] <<  '\n';
    }
}