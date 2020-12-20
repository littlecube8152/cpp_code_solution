#include <iostream>
using namespace std;

char alph(int index){
    index = index - 64  + 26;
    index %= 26;
    index += 64;
    return (char)index;
}

int main()
{
    int shift, len;
    string input;
    cin >> shift >> input;
    len = input.size();
    for (int i = 0; i < len; i ++){
        int convert = (int)input[i];
        input[i] = alph(convert - shift);
    }
    cout << input << '\n';
}

    