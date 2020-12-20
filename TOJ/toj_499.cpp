#include <iostream>
using namespace std;

int main()
{
    string tag, package;
    int id = 1, packages;
    getline(cin, tag);
    cin >> packages;
    getline(cin, package);
    for (id = 1; id <= packages; id ++){
        getline(cin, package);
        if (package == tag){
            cout << id << " ";
        }
    }
    cout <<  '\n';
}