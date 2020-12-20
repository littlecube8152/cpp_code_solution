#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int count;
    double average = 0;
    double average_sqrt = 0;
    cin >> count;
    for (long long int i = 1; i <= count; i++)
    {
        int a;
        cin >> a;
        average += a;
        if(a < 1000) {
            average_sqrt += sqrt(a)*100;
           
        }else{
            average_sqrt += a;
        }
    }
    
    average /= count;
        average_sqrt /= count;
    if(average < 1000){
        average = average_sqrt;
    }
    average = (int)(average);
    cout << average << '\n';
}

