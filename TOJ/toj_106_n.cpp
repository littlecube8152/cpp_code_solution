#include <iostream>
using namespace std;

int main()
{
    
    long output = 2;
    while (1)
    {
        output *= 2;
        output += 1;
        int test = output % 71;
        if ( test== 0)
        {
            cout << output << endl;
            break;
        }
    }
    if((output%=3)==0){
    cout << "right" << endl;
    }else{
    cout << "left" << endl;
    }

}