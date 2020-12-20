#include <iostream>
#include <vector>
using namespace std;
vector<int> add(vector<int> a, vector<int> b)
{
    vector<int> result(1000, 0);
    for (int i = 0; i < 1000; i++)
    {
        result[i] += (a[i] + b[i]);
        result[i + 1] += (result[i] / 10);
        result[i] %= 10;
    }
    return result;
}
void print(vector<int> a)
{
    int i = 999;
    for (; a[i] == 0; i--)
    {
    }
    for (; i >= 0; i--)
    {
        cout << a[i];
    }
    cout << '\n';
}

int main()
{
    vector<vector<int>> p(3, vector<int>(1000, 0));
    int index;
    cin >> index;
    p[1][0] = 1;
    p[2][0] = 1;
    for (int i = 3; i <= index; i++)
    {
        p[0].assign(p[1].begin(), p[1].end());
        p[1].assign(p[2].begin(), p[2].end());
        p[2] = add(p[0], p[1]);
    }
    print(p[2]);
}