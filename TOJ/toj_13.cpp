#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    ll capacity, items;
    while (cin >> capacity >> items)
    {

        ll backpack[100010] = {0}, item[2], max = 0;
        for (ll i = 0; i < items; i++)
        {
            cin >> item[0] >> item[1];

            for (ll j = capacity; j >= 0; j--)
            {
                if (item[0] <= j)
                {
                    if (backpack[j] + item[1] > backpack[j - item[0]])
                    {
                        backpack[j - item[0]] = backpack[j] + item[1];
                        if (max < backpack[j] + item[1])
                            max = backpack[j] + item[1];
                        //cout << "Putting: " << item[0] << " Capacity: " << j << " Reamin Capacity: " << j - item[0] << " Value: " << backpack[j] + item[1] << '\n';
                    }
                }
            }
        }
        cout << max << '\n';
    }
}