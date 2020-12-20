#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        int student_count, student[20000], query_count;
        int cal[30005] = {0};
        cin >> student_count;
        for (int i = 0; i < student_count; i++)
        {
            cin >> student[i];
        }
        for (int i = 0; i < student_count; i++)
        {
            for (int j = i + 1; j < student_count; j++)
            {
                int data = student[j] + student[i];
                if (cal[data] == 0 && student[j] != 0 && student[i] != 0)
                {
                    cal[data] = 1;
                }
            }
        }
        cin >> query_count;

        for (int i = 0; i < query_count; i++)
        {
            int data;
            cin >> data;
            if (data > 30000)
            {
                cout << "So Bad!\n";
            }
            else if (cal[data] == 1)
            {
                cout << "Good!\n";
            }
            else
            {
                cout << "So Bad!\n";
            }
        }
    }
}