#include <iostream>
#include <queue>
#define cin std::cin
#define cout std::cout
int map[1005][1005] = {{0}};
int height, width;
std::queue<int> list_x;
std::queue<int> list_y;
long long int distance[1005][1005] = {{0}};

int main()
{
    cin >> height >> width;
    for (int j = 0; j < width + 2; j++)
    {
        map[0][j] = 1;
    }
    for (int i = 1; i < height + 1; i++)
    {
        map[i][0] = 1;
        for (int j = 1; j < width + 1; j++)
        {
            cin >> map[i][j];
        }
        map[i][width + 1] = 1;
    }
    for (int j = 0; j < width + 2; j++)
    {
        map[height + 1][j] = 1;
    }

    int start[2], end[2];
    cin >> start[0] >> start[1] >> end[0] >> end[1];
    start[0]++;
    start[1]++;
    end[0]++;
    end[1]++;

    list_x.push(start[0]);
    list_y.push(start[1]);
    map[start[0]][start[1]] = -1;
    while (!list_x.empty())
    {
        if (list_x.front() == end[0] && list_y.front() == end[1])
        {
            break;
        }
        if (map[list_x.front()][list_y.front()] == -1)
        {

            if (map[list_x.front() + 1][list_y.front()] == 0)
            {
                list_x.push(list_x.front() + 1);
                list_y.push(list_y.front());
                map[list_x.front() + 1][list_y.front()] = -1;
                distance[list_x.front() + 1][list_y.front()] = distance[list_x.front()][list_y.front()] + 1;
            }
            if (map[list_x.front() - 1][list_y.front()] == 0)
            {
                list_x.push(list_x.front() - 1);
                list_y.push(list_y.front());
                map[list_x.front() - 1][list_y.front()] = -1;
                distance[list_x.front() - 1][list_y.front()] = distance[list_x.front()][list_y.front()] + 1;
            }
            if (map[list_x.front()][list_y.front() + 1] == 0)
            {
                list_x.push(list_x.front());
                list_y.push(list_y.front() + 1);
                map[list_x.front()][list_y.front() + 1] = -1;
                distance[list_x.front()][list_y.front() + 1] = distance[list_x.front()][list_y.front()] + 1;
            }
            if (map[list_x.front()][list_y.front() - 1] == 0)
            {
                list_x.push(list_x.front());
                list_y.push(list_y.front() - 1);
                map[list_x.front()][list_y.front() - 1] = -1;
                distance[list_x.front()][list_y.front() - 1] = distance[list_x.front()][list_y.front()] + 1;
            }
            map[list_x.front()][list_y.front()] = -2;
            list_x.pop();
            list_y.pop();
        }
    }

    cout << '\n';
    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (map[i][j] == 1)
            {
                cout << ". ";
            }
            else
            {
                cout << distance[i][j] << " ";
            }

            if (distance[i][j] < 10)
                cout << " ";
        }
        cout << '\n';
    }
    cout << '\n';

    if (distance[end[0]][end[1]] == 0)
    {
        cout << "-1\n";
        return 0;
    }
    cout << distance[end[0]][end[1]] << '\n';
}