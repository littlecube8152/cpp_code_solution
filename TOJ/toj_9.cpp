#include <iostream>
#include <queue>
#define DISTANT_INFINITY -2
#define cin std::cin
#define cout std::cout
struct vertex
{
    int height;
    int color = 0; //0 = White, 1 = Grey, 2 = Black
};

bool road[10010][10010] = {{0}};     //Store all given roads
std::queue<int> list;                    //Temp the visit queue
int distance_BFS[10001] = {0}; //Store visit distance
int distance_DFS[10005] = {0};
//long long int predecessor_BFS[10005] = {0}; //Store previous visited one
//long long int predecessor_DFS[10005] = {0};
vertex node[10005] = {{0, 0}}; //Using self-defined class to store visit-discover state and height

int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int count;
    cin >> count;
    for (int index = 1; index <= count; index++)
    {
        int node_count, roads, start, BFS_min = DISTANT_INFINITY, DFS_min = DISTANT_INFINITY;
        cin >> node_count >> roads >> start;

        //Part 1: Init
        int lowest = 10000000;
        for (int i = 0; i < node_count; i++)
        {
            for (int j = 0; j < node_count; j++)
                road[i][j] = 0;
            //predecessor_BFS[i] = 0;
            //predecessor_DFS[i] = 0;
            cin >> node[i].height; //Enter each node's height
            node[i].color = 0;
            if (node[i].height < lowest) //Find the end of the Mountain trail
            {
                lowest = node[i].height;
            }
        }
        for (int i = 0; i < roads; i++)
        {
            long long int a, b;
            cin >> a >> b;
            road[a][b] = 1; //Enter each road (go)
            road[b][a] = 1; //Enter each road (back)
        }

        list.push(start);
        node[start].color = 1; //First visited
        //predecessor_BFS[start] = -1; //Label start node
        distance_BFS[start] = 0;

        //Part 2: BFS
        while (!list.empty())
        {
            if (node[list.front()].color == 1) //Testing if it is grey (discovered, not visited)
            {
                if (node[list.front()].height == lowest)
                {
                    BFS_min = distance_BFS[list.front()];
                    list = {};
                    break;
                }
                for (int j = 0; j < node_count; j++) //Discovering every single node which is white(==0) and able to reach
                {
                    if (node[j].color == 0 && road[list.front()][j] == 1)
                    {
                        list.push(j);
                        node[j].color = 1;
                        //predecessor_BFS[j] = list.front();
                        distance_BFS[j] = distance_BFS[list.front()] + 1;
                    }
                }
                node[list.front()].color = 2;
                list.pop();
            }
        }

        //Part 3: Init Color to if-based-DFS
        for (int i = 0; i < node_count; i++)
        {
            node[i].color = 0;
        }
        list.push(start);
        node[start].color = 1; //First visited
        //predecessor_DFS[start] = -1; //Label start node
        distance_DFS[start] = 0;

        //Part 4: if-based-DFS
        for (int i = 0; i < node_count; i++)
        {
            if (list.empty() == true)
            {
                break;
            }
            if (node[list.front()].color == 1) //Testing if it is grey (discovered, not visited)
            {
                if (node[list.front()].height == lowest)
                {
                    DFS_min = distance_DFS[list.front()];
                    list = {};
                    break;
                }
                int tmp = -1;
                int lowest_d = 0;
                for (int j = 0; j < node_count; j++) //Discovering every single node which is white(==0) and able to reach
                {
                    if (node[j].color == 0 && road[list.front()][j] == 1)
                    {
                        if ((node[list.front()].height - node[j].height) > lowest_d)
                        {
                            lowest_d = (node[list.front()].height - node[j].height);
                            tmp = j;
                        }
                    }
                }
                if (tmp != -1)
                {
                    list.push(tmp);
                    node[tmp].color = 1;
                    distance_DFS[tmp] = distance_DFS[list.front()] + 1;
                }
                node[list.front()].color = 2;
                list.pop();
            }
        }
        
        //cout << "--------BFS--------\nNODE  ";for (int i = 0; i < node_count; i++){cout << i << " ";}cout << "\nPRED  ";for (int i = 0; i < node_count; i++){cout << predecessor_BFS[i] << " ";}cout << "\nDIST  ";for (int i = 0; i < node_count; i++){cout << distance_BFS[i] << " ";}cout << "\n--------DFS--------\nNODE  ";for (int i = 0; i < node_count; i++){cout << i << " ";}cout << "\nPRED  ";for (int i = 0; i < node_count; i++){cout << predecessor_DFS[i] << " ";}cout << "\nDIST  ";for (int i = 0; i < node_count; i++){cout << distance_DFS[i] << " ";}cout << '\n'<< end;
             
        if (DFS_min == -2)
        {
            if (BFS_min == -2)
            {
                cout << "Case #" << index << ": Call 119!\n";
            }
            else
            {
                cout << "Case #" << index << ": " << (BFS_min * 6) << "\n";
            }
        }
        else
        {
            cout << "Case #" << index << ": " << (BFS_min * 6 - DFS_min) << "\n";
        }
    }
}