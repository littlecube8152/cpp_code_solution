#include <iostream>
using namespace std;

bool check_length(int k)
{
    cout << "is length <= " << k << "?\n";
    bool res;
    cin >> res;
    return res;
}

bool check_position(int i, char c)
{
    cout << "is char at position " << i << " <= " << c << "?\n";
    bool res;
    cin >> res;
    return res;
}

void report(string s)
{
    cout << "the answer is " << s << '\n';
}
