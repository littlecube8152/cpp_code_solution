#include <iostream>
#include <vector>
using namespace std;
struct stick
{
    long long int height;
    long long int sight;
};

int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count;
    while (cin >> count)
    {
        vector<stick> peak;
        peak.push_back({2200000000, 0});
        long long int result = -1, old_result, stick = -1, old_stick;
        for (int i = 0; i < count ; i++)
        {
            old_result = result;
            old_stick = stick;
            result = 0;

            cin >> stick;
            if (stick > old_stick)
            {
                result = old_result + 1;
                while (stick > peak.back().height)
                {
                    result += peak.back().sight + 1;
                    peak.pop_back();
                }
            }
            if (stick <= old_stick)
            {
                peak.push_back({old_stick, old_result});
                result = 0;
            }
            cout << result;
            if (i == count - 1)
            {
                cout << '\n';
            }
            else
            {
                cout << " ";
            }
        }
    }
}