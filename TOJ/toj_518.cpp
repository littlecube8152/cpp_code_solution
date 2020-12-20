#include <iostream>
using namespace std;
int main()
{
    long long int correct[100005] = {0};
    long long int correct_index = 0;
    long long int mistake_counter = 0;
    long long int mistake, correct_len, player_len;
    bool triggered = true;
    cin >> correct_len >> mistake;
    for (long long int i = 0; i < correct_len; i++)
    {
        cin >> correct[i];
    }
    correct[correct_len] = 10;
    cin >> player_len;
    for (int i = 0; i < player_len; i++)
    {
        int command;
        cin >> command;
        if (command == correct[correct_index])
        {
            correct_index++;
            mistake_counter = 0;
        }
        else
        {
            mistake_counter++;
            //cout << "Mistake Checking " << correct[correct_index] << " Tried " << mistake_counter << "\n";
        }
        if (mistake_counter > mistake)
        {
            triggered = false;
            break;
        }
    }
    if (triggered == false)
    {
        cout << "Failed..\n";
    }
    else if (correct_index >= correct_len)
    {
        cout << "Triggered!!\n";
    }
    else
    {
        cout << "Failed..\n";
    }
}