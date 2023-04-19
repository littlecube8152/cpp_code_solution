#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<vector<int>> solutionForRule1(const map<int, int> &counts)
{
    vector<vector<int>> solution;
    for (auto [color, count] : counts)
        solution.emplace_back(count, color);
    return solution;
}

vector<vector<int>> solutionForRule2(const map<int, int> &counts, int maxCount)
{
    vector<vector<int>> solution(maxCount);
    for (auto [color, count] : counts)
    {
        for (int i = 0; i < count; ++i)
            solution[i].push_back(color);
    }
    return solution;
}

int main()
{
    int n;
    cin >> n;

    map<int, int> counts;
    int maxCount = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        maxCount = max(maxCount, ++counts[x]);
    }

    const int rule = counts.size() < maxCount ? 1 : 2;
    const auto solution = rule == 1 ? solutionForRule1(counts) : solutionForRule2(counts, maxCount);

    cout << solution.size() << ' ' << rule << endl;

    for (const auto &colors : solution)
    {
        cout << colors.size();
        for (auto color : colors)
            cout << ' ' << color;
        cout << endl;
    }

    return 0;
}
