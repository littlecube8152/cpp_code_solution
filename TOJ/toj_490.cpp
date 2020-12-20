#include <iostream>
using namespace std;

int line[10000000];
int q[10000000][2];

void spray(long long int locate, long long int id)
{
    for (int i = 0; i < locate; i++)
        line[i] = id;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int count, game;
    cin >> count;
    for (long long int i = 0; i < count; i++)
        cin >> line[i];
    cin >> game;
    for (long long int i = 0; i < game; i++)
    {
        cin >> q[i][0] >> q[i][1];
    }

    int index = 0;
    for (long long int i = game - 1; i >= 0; i--)
    {
        for (; index < q[i][0]; index++)
        {
            line[index] = q[i][1];
        }
    }
    for (long long int i = 0; i < count; i++)
        cout << line[i] << " ";
    cout << '\n';
}
