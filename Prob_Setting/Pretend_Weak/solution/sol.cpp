#include <iostream>
using namespace std;

int n, sum;

int main()
{
    cin >> n;

    if (n == 1)
    { 
        // Notice that "n" may be 1 so there will no classmate in your class
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        // Calaulate the sum instead of storing average can avoid decimal points
        // It can be proved that the answer k >= (a1 + ... + an-1) / n-1 and k must be an integer 
        int x;
        cin >> x;
        sum += x;
    }
    //k = ceil(sum / n-1), this is just another way by using integer 
    cout << (sum + n - 2) / (n - 1) << '\n'; 
}