#include <iostream>
using namespace std;
int main()
{
    int para[3];
    cin >> para[0];
    cin >> para[1];
    cin >> para[2];
    for (int a = 1; a <= 9; a++)
    {
        for (int b = 0; b <= 9; b++)
        {
            for (int c = 0; c <= 9; c++)
            {
                for (int d = 0; d <= 9; d++)
                {
                    if(((float)(a-b)/((int)para[0] - 0.5)) > 0.0 && ((float)(b-c)/((int)para[1] - 0.5)) > 0.0 && ((float)(c-d)/((int)para[2] - 0.5)) > 0.0){
                        
                        cout << a << b << c << d <<'\n';
                    }

                }
            }
        }
    }
}