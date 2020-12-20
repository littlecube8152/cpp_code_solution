#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int dice[1005] = {0};
    int x = 0, y = 0, count;
    int cal[2000000] = {0};
    vector<int> possible_y = {};

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> dice[i];
        y += dice[i];
    }
    sort(dice, dice + count);
    possible_y.push_back(y);

    for (int i = 0; i < count; i++)
    {
        for (int i = 0; i < possible_y.size(); i++)
        {
            int tmp = possible_y.push_back(y);
        }
    }
}
