#include <iostream>
using namespace std;
int list[1000000] = {0};
int prime[100000] = {0};
int main()
{

    int number = 1;
    prime[0] = 2;
    list[1] = 0;
    list[2] = 1;
    for (int i = 1; number <= 1000000; i++)
    {
        bool is_prime = false;
        while (!is_prime)
        {
            number++;
            is_prime = true;
            for (int j = 0; j < i; j++)
            {
                if (number % prime[j] == 0)
                {
                    list[number] = list[number - 1];
                    is_prime = false;
                    break;
                }
            }
        }
        prime[i] = number;
        list[number] = list[number - 1] + 1;
    }
    cout << '\n';
    int tmp;
    while (cin >> tmp)
    {
        cout << list[tmp];
    }
}