#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int M, K, D;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> M >> K >> D;
    auto T = make_tuple(M, K, D);
    if (T == tuple<int, int, int>{5, 3, 2})
        cout << R"(10
11100
11010
11001
10110
10101
10011
01110
01101
01011
00111
)";
    if (T == tuple<int, int, int>{8, 5, 3})
    {
        bitset<8> b[8];
        vector<int> v;
        bool poat = 0;
        for (int i = 0; i < (1 << 8); i++)
            if (__builtin_popcount(i) == 5)
                v.emplace_back(i);
        while (!poat)
        {
            shuffle(v.begin(), v.end(), rd);
            int cur = 0;
            for (int i = 0; i < v.size() && cur < 8; i++)
            {
                bool valid = 1;
                b[cur] = v[i];
                for (int j = 0; j < cur; j++)
                    if ((b[j] & b[cur]).count() > D)
                        valid = 0;
                if (valid)
                    cur++;
            }
            if (cur == 8)
                poat = 1;
        }
        cout << 8 << '\n';
        for (int i = 0; i < 8; i++)
            cout << b[i] << '\n';
    }
    if (T == tuple<int, int, int>{20, 12, 7})
    {
        cout << R"(16
00000000111111111111
00011111000001111111
00011111111110000011
01100111001110011101
01100111110011100110
01111001001111101010
01111001110100110101
01111110111001011000
10101011011011110001
10110110010110111010
10110110101101100101
11010101011101010110
11011010010111001101
11011010101010110110
11101100011000101111
11101100100111010011
)";
    }
    #ifndef _GLIBCXX_DEBUG
    if (T == tuple<int, int, int>{64, 32, 16})
    {
        bitset<64> b[128];
        b[0].flip();
        for (int i = 32; i >= 1; i /= 2)
        {
            int cur = 64 / i;
            for (int j = 0; j < cur; j++)
            {
                b[cur + j] = b[j];
                for (int k = 0; k < 64; k++)
                    if (k / i % 2 == 0)
                        b[cur + j][k] = ~b[cur + j][k];
            }
        }
        cout << 125 << '\n';
        for (int i = 2; i < 127; i++)
            cout << b[i] << '\n';
    }
    if (T == tuple<int, int, int>{65, 32, 17})
    {
        bitset<64> b[128];
        b[0].flip();
        for (int i = 32; i >= 1; i /= 2)
        {
            int cur = 64 / i;
            for (int j = 0; j < cur; j++)
            {
                b[cur + j] = b[j];
                for (int k = 0; k < 64; k++)
                    if (k / i % 2 == 0)
                        b[cur + j][k] = ~b[cur + j][k];
            }
        }
        cout << 125 << '\n';
        for (int i = 2; i < 127; i++)
            cout << b[i] << 0 << '\n';
    }
    if (T == tuple<int, int, int>{49, 7, 3})
    {
        bitset<49> b[2401];
        for (int i = 0; i < 7; i++)
            for (int j = 0; j < 7; j++)
                for (int k = 0; k < 7; k++)
                    for (int l = 0; l < 7; l++)
                        for (int p = 0; p < 7; p++)
                            b[i * 343 + j * 49 + k * 7 + l][p * 7 + (i * p * p * p + j * p * p + k * p + l) % 7] = 1;
        cout << 2401 << '\n';
        for (int i = 0; i < 2401; i++)
            cout << b[i] << '\n';
    }
    if (T == tuple<int, int, int>{121, 11, 4})
    {
        bitset<121> b[161051];
        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 11; j++)
                for (int k = 0; k < 11; k++)
                    for (int l = 0; l < 11; l++)
                        for (int m = 0; m < 11; m++)
                            for (int p = 0; p < 11; p++)
                                b[i * 14641 + j * 1331 + k * 121 + l * 11 + m][p * 11 + (i * p * p * p * p + j * p * p * p + k * p * p + l * p + m) % 11] = 1;
        cout << 161051 << '\n';
        for (int i = 0; i < 161051; i++)
            cout << b[i] << '\n';
    }
    if (T == tuple<int, int, int>{1369, 37, 2})
    {
        bitset<1369> b[50653];
        for (int i = 0; i < 37; i++)
            for (int j = 0; j < 37; j++)
                for (int k = 0; k < 37; k++)
                    for (int p = 0; p < 37; p++)
                        b[i * 1369 + j * 37 + k][p * 37 + (i * p * p + j * p + k) % 37] = 1;
        cout << 50653 << '\n';
        for (int i = 0; i < 50653; i++)
            cout << b[i] << '\n';
    }
    if (T == tuple<int, int, int>{49, 7, 5})
    {
        bitset<49> b[117649];
        for (int i = 0; i < 7; i++)
            for (int j = 0; j < 7; j++)
                for (int k = 0; k < 7; k++)
                    for (int l = 0; l < 7; l++)
                        for (int m = 0; m < 7; m++)
                            for (int n = 0; n < 7; n++)
                                for (int p = 0; p < 7; p++)
                                    b[i * 16807 + j * 2401 + k * 343 + l * 49 + m * 7 + n][p * 7 + (i * p * p * p * p * p + j * p * p * p * p + k * p * p * p + l * p * p + m * p + n) % 7] = 1;
        cout << 117649 << '\n';
        for (int i = 0; i < 117649; i++)
            cout << b[i] << '\n';
    }
    #endif
}
