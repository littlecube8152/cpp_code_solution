#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tmpStr;
    int T;
    while(cin >> T){
    getline(cin, tmpStr);
    getline(cin, tmpStr);
    char output[tmpStr.length()+1];
    int index = 0;
    for (int j = 0; j < T; j++)
    {
        for (int i = 0; i < tmpStr.length() / T; i++)
        {
            output[index] = tmpStr[T * i + j];
            
            index++;
        }
    }
    for (int i = 0; i < tmpStr.length(); i++)
    {
        cout << output[i];
    }
    cout << endl;
}}
