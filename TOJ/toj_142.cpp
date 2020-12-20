#include <iostream>
using namespace std;
int main()
{
    int board[4][4] = {{0}};
    int empty = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char tmp;
            cin >> tmp;
            if (tmp == '#')
            {
                empty++;
                board[i][j] = 0;
            }
            else if (tmp == 'O')
            {
                board[i][j] = 1;
            }
            else
            {
                board[i][j] = -1;
            }
            board[i][3] += board[i][j];
            board[3][j] += board[i][j];
        }
    }
    if (board[0][3] == 3 || board[1][3] == 3 || board[2][3] == 3 ||
        board[3][0] == 3 || board[3][1] == 3 || board[3][2] == 3 ||
        (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) ||
        (board[2][0] == 1 && board[1][1] == 1 && board[0][2] == 1))
    {
        cout << "A wins.\n";
    }
    else if (board[0][3] == -3 || board[1][3] == -3 || board[2][3] == -3 ||
             board[3][0] == -3 || board[3][1] == -3 || board[3][2] == -3 ||
             (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1) ||
             (board[2][0] == -1 && board[1][1] == -1 && board[0][2] == -1))
    {
        cout << "B wins.\n";
    }
    else if (empty > 0)
    {
        cout << "Playing\n";
    }
    else
    {
        cout << "Draw\n";
    }
}