#include "highway.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
    int N;
    cin >> N;
    ofstream cout("sample.in");
    int A = rd() % N, B = rd() % N;
    while(B == A)
        B = rd() % N;
    cout << N << ' ' << N - 1 << ' ' << 10 << ' ' << 16 << ' ' << A << ' ' << B << '\n';
    for (int i = 1; i < N; i++)
        cout << i - 1 << ' ' << i << '\n';
    cout.close();
}