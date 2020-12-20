#include <iostream>
using namespace std;
int main()
{
    int a;

    int me = 0;
    int oppoment = 0;
    int my[100000] = {0};
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> my[i];
    }

    for (int i = 0; i < a; i++)
    {
        int n = 0;
        cin >> n;
        my[i] -= n;
        if (my[i] == -2 || my[i] == -3 || my[i] == 5)
        {
            me += 3;
            oppoment -= 1;
        }
        else if (my[i] == 2 || my[i] == 3 || my[i] == -5)
        {
            me -= 1;
            oppoment += 3;
        }
        else
        {
            me += 1;
            oppoment += 1;
        }
    }
    cout << me << " " << oppoment << '\n';
}