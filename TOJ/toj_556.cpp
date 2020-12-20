#include <iostream>
#include <math.h>
using namespace std;

long long int work, part, money;
long long int works[100005], paid[100005];
long long int times[100005], max_time = 0;

long long int binary_search(long long int max, long long int min)
{
    long long int tmp_money = money;
    if (max - min <= 1)
    {

        for (long long int i = 0; i < work; i++)
        {

            tmp_money -= ceil(((double)part - ((double)min * (double)works[i])) / (double)paid[i]);
            if (tmp_money < 0)
            {
                return max;
            }
        }
        return min;
    }
    else
    {
        long long int mid = (max + min) / 2;

        for (long long int i = 0; i < work; i++)
        {
            tmp_money -= ceil(((double)part - ((double)mid * (double)works[i])) / (double)paid[i]);
            if (tmp_money < 0)
            {
                cout << "Binary Searching: " << max << " to " << mid << '\n';
                return binary_search(max, mid + 1);
            }
        }
        cout << "Binary Searching: " << mid << " to " << min << '\n';
        return binary_search(mid, min);
    }
}

int main()
{

    cin >> work >> part >> money;
    for (long long int i = 0; i < work; i++)
    {
        cin >> works[i];
        times[i] = ceil((float)part / (float)works[i]);
        if (times[i] > max_time)
        {
            max_time = times[i];
        }
    }
    for (long long int i = 0; i < work; i++)
    {
        cin >> paid[i];
    }

    cout << binary_search(max_time, 0) << "\n";
}