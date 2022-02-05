#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int main()
{
    int N = 63, M;
    vector<pair<pii, int>> v;
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            v.emplace_back(make_pair(pii{i, j}, (j - i) * 2 - 1));
    M = v.size();
    cout << N << " " << M << '\n';
    for(auto [e, w] : v)
        cout << e.F << " " << e.S << " " << w << '\n';
    
}