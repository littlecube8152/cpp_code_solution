#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int p[5005], a[5005];
bitset<1 << 30> b;

signed main()
{
    int N;
    cin >> N;
    b = ~b;
    b[0] = 0;
    // XOR [i, j] = p[i - 1] XOR p[j];
    // XOR [x < y]
    // XOR [x < y <= z < w]
    ofstream cout("G.txt");
    for (int i = 1; i <= N; i++)
    {
        p[i] = b._Find_first();
        a[i] = p[i] ^ p[i - 1];
        for (int j = 0; j <= i; j++)
            for (int k = 0; k <= j; k++)
                b[p[i] ^ p[j] ^ p[k]] = 0;
        cerr << i << '\n';
    }
    cout << "{";
    for (int i = 1; i <= N; i++)
        cout << a[i] << ",}"[i == N];
    cout.close();
}