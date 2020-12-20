#include <iostream>
#include <queue>
using namespace std;
class vertex
{
public:
    int color = 0;
    vector<int> path = vector<int>();
};
int node_count, path_count;
vertex node[100000];
queue<int> list;

int main()
{
    while (cin >> node_count)
    {
        cin >> path_count;
        for (int i = 0; i < path_count; i++)
        {
            int a, b;
            cin >> a >> b;
            node[a].path[b] = 0;
            node[b].path[a] = 0;
        }
        list.push(0);
        int visited_node = 0;

        while (!list.empty())
        {
            node[list.front()].color = 2;
            visited_node++;
            for (int i = 0; i < node_count; i++)
            {
                if (node[list.front()].path[i] == 0)
                {
                    continue;
                }
                if (node[list.front()].color == 0)
                {
                    list.push(i);
                    node[i].color = 1;
                }
            }
            list.pop();
        }
        if (visited_node == node_count){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}