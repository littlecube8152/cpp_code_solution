#include <iostream>
#include <vector>
using namespace std;

int array[1000];
bool is_cal[1000][1000] = {{0}};
int cal[1000][1000] = {{0}};
int total = 0;

int dp(long int begin, long int end, int turns)
{
    if (begin == end)
    {
        return turns * array[begin];
    }
    else
    {
        if (!is_cal[begin][end])
        {
            int take_front = dp(begin + 1, end, -turns) + turns * array[begin];
            int take_end = dp(begin, end - 1, -turns) + turns * array[end];
            if (turns == 1)
                cal[begin][end] = max(take_front, take_end);
            else
                cal[begin][end] = min(take_front, take_end);
            

            is_cal[begin][end] = 1;
        }
        return cal[begin][end];
    }
}

int main()
{

    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> array[i];
        total += array[i];
    }

    int result = dp(0, count - 1, 1);
    cout << (total + result) / 2 << " " << (total - result) / 2 << '\n';
}