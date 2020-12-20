#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
int main()
{
    clock_t st, end; //建立clock_t變數(長整數形態)以記錄時間，以毫秒(0.001秒)為單位
    

    long long int p[16385] = {0};
    int a;
    cin >> a;
    st = clock();
    p[0] = 2;
    int number = 1;
    for (int i = 1; i < 16385; i++)
    {
        bool prime = false;
        while (!prime)
        {
            number += 2;
            prime = true;
            for (int j = 0; j < i; j++)
            {
                if(p[j]> sqrt(number)){
                    break;
                }
                if (number % p[j] == 0)
                {
                    prime = false;
                    break;
                }
            }
        }
        //cout << number << " ";
        p[i] = number;
    }
    end = clock();
    cout << p[a] - 1 << '\n';
    cout << "Time: " << end - st << " ms.";
}