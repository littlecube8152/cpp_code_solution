#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

string input;
vector<long long> one;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    getline(cin, input);

    int i = 0;
    while (i < input.length())
    {
        int t = (int)input[i];
        if (t >= 97)
        {
            t -= 39;
        }
        t -= 48;

        if (t / 8 % 2)
            one.push_back(4 * (input.length() - i - 1) + 3);
        if (t / 4 % 2)
            one.push_back(4 * (input.length() - i - 1) + 2);
        if (t / 2 % 2)
            one.push_back(4 * (input.length() - i - 1) + 1);
        if (t % 2)
            one.push_back(4 * (input.length() - i - 1));
        i++;
    }
    one.push_back(4611686018427387903);
    sort(one.begin(), one.end());

    set<long long> v;
    for (int index = 0; index < one.size() - 3; index++)
    {
        vector<long long> gap = {one.at(index), one.at(index + 1), one.at(index + 2), one.at(index + 3)};
        if ((gap[0] + gap[2] == 2 * gap[1]) && (gap[1] + gap[3] >= 2 * gap[2]) && (gap[0] % (gap[1] - gap[0]) == 0))
        {
            v.insert((gap[1] - gap[0]));
        }
    }
    v.erase(0);
    for (auto i : v)
    {
        cout << i << '\n';
    }
}
