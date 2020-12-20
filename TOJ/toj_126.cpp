#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int question, request;
vector<int> score = {0};
vector<int> tmp;
int main()
{
    cin >> question >> request;
    ///*
    for (int i = 0; i < question; i++)
    {
        int s;
        cin >> s;
        bool cal[20005] = {0}; //0-9999 -> -10000 ~ -1
        for (int j = 0; j < score.size(); j++)
        {
            int a = score[j] + s;
            if (!cal[10000 + a])
            {
                tmp.insert(lower_bound(tmp.begin(), tmp.end(), a), a);
                cal[10000 + a] = 1;
            }
            int b = score[j] - s;
            if (!cal[10000 + b])
            {
                tmp.insert(lower_bound(tmp.begin(), tmp.end(), b), b);
                cal[10000 + b] = 1;
            }
        }
        score = tmp;
        tmp = {};
    }
    /*
    cout << "Possible: \n";
    for (int j = 0; j < score.size(); j++)
    {
        cout << score[j] << '\n';
    }
    cout << "Test: \n";
    */
    for (int i = 0; i < request; i++)
    {
        int s;
        cin >> s;
        cout << score.at((lower_bound(score.begin(), score.end(), s) - score.begin())) << '\n';
    }
}