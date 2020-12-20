#include <iostream>
using namespace std;
int main()
{
    long long int speed = 299792458;
    cout << "1 Light-second(LS) is "<< speed << " metres."<< '\n';
    speed *= 60;
    cout << "1 Light-minute(LM) is "<< speed << " metres."<< '\n';
    speed *= 60;
    cout << "1 Light-hour(LH) is "<< speed << " metres."<< '\n';
    speed *= 24;
    cout << "1 Light-day(LD) is "<< speed << " metres."<< '\n';
    speed *= 7;
    cout << "1 Light-week(LW) is "<< speed << " metres."<< '\n';
    speed *= 365;
    speed /= 7;
    cout << "1 Light-year(LY) is "<< speed << " metres."<< '\n';
    

}