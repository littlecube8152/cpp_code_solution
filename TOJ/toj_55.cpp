#include <iostream>
#include <algorithm>
using namespace std ;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    long long int input;
    cin >> input;
    long long int disk[200000] = {0};
    for (long long int i = 0; i < input; i++)
    {
        cin >> disk[i];
    }
    sort(disk, disk + input) ;
    long long int test;
    cin >> test;
    for (long long int i = 1; i <= test; i++)
    {
        long long int file;
        cin  >> file;
        cout << (upper_bound(disk,disk+input,file) - lower_bound(disk,disk+input,file)) << '\n';
    }
}