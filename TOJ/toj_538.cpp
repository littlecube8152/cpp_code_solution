#include <iostream>
using namespace std;

int main()
{
    double math, eng, sci, data, pro, score, tagert;
    cin >> eng >> math >> sci >> data >> pro >> tagert;

    score = (((eng * 1.25) + (math * 2) + sci) / 63.75) * 20 + 0.4 * (pro + data);
    if (score >= tagert)
    {
        cout << "YA\n";
    }
    else
    {
        cout << "QQ\n";
    }
}