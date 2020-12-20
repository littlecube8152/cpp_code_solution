#include <iostream>
#include <queue>
using namespace std;

int block[1002][1002] = {{0}};
int m, n;
int x, y, end_x, end_y;
queue<int> list_x;
queue<int> list_y;

void list_push(int x, int y)
{
    list_x.push(x);
    list_y.push(y);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m + 2; i++)
    {
        block[i][0] = 1;
        block[i][n + 1] = 1;
    }
    for (int i = 0; i < n + 2; i++)
    {
        block[0][i] = 1;
        block[m + 1][i] = 1;
    }

    cin >> x >> y;
    list_push(x, y);
    block[x][y] = 2;

    cin >> end_x >> end_y;

    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> x >> y;
        block[x][y] = 1;
    }
    for (int i = 0; i < 4 * n * m && !list_x.empty(); i++)
    {
        x = list_x.front();
        y = list_y.front();
        list_x.pop();
        list_y.pop();
        if (block[x][y] == 2)
        {
            block[x][y] = 4;

            if (block[x + 1][y] == 0)
            {
                list_push(x + 1, y);
                block[x + 1][y] = 2;
            }

            if (block[x - 1][y] == 0)
            {
                list_push(x - 1, y);
                block[x - 1][y] = 2;
            }

            if (block[x][y + 1] == 0)
            {
                list_push(x, y + 1);
                block[x][y + 1] = 2;
            }

            if (block[x][y - 1] == 0)
            {
                list_push(x, y - 1);
                block[x][y - 1] = 2;
            }
            /*
            for (int i = 0; i < m + 2; i++)
            {
                for (int j = 0; j < n + 2; j++)
                {
                    cout << block[i][j] << " ";
                }
                cout << '\n';
            }
            cout << '\n';
            */
        }
    }
    if (block[end_x][end_y] == 0)
    {
        cout << "Harakiri!\n";
    }
    else
    {
        cout << "Cool!\n";
    }
}
