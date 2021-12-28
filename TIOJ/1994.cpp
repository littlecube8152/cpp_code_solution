/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int N, arr[2048][2048], i;

void solve(int &idx, int size, int x, int y, int dir)
{
    if (size == 1)
    {
        if (dir == 0)
        {
            arr[x][y] = idx++;
            arr[x + 1][y] = idx++;
            arr[x + 1][y + 1] = idx++;
            arr[x][y + 1] = idx++;
        }
        if (dir == 1)
        {
            arr[x + 1][y + 1] = idx++;
            arr[x + 1][y] = idx++;
            arr[x][y] = idx++;
            arr[x][y + 1] = idx++;
        }
        if (dir == 2)
        {
            arr[x][y] = idx++;
            arr[x][y + 1] = idx++;
            arr[x + 1][y + 1] = idx++;
            arr[x + 1][y] = idx++;
        }
        if (dir == 3)
        {
            arr[x + 1][y + 1] = idx++;
            arr[x][y + 1] = idx++;
            arr[x][y] = idx++;
            arr[x + 1][y] = idx++;
        }
    }
    else
    {
        size--;
        if (dir == 0)
        {
            solve(idx, size, x, y, (dir ^ 2));
            solve(idx, size, x + (1 << size), y, dir);
            solve(idx, size, x + (1 << size), y + (1 << size), dir);
            solve(idx, size, x, y + (1 << size), (dir ^ 1));
        }
        if (dir == 1)
        {
            solve(idx, size, x + (1 << size), y + (1 << size), (dir ^ 2));
            solve(idx, size, x + (1 << size), y, dir);
            solve(idx, size, x, y, dir);
            solve(idx, size, x, y + (1 << size), (dir ^ 1));
        }
        if (dir == 2)
        {
            solve(idx, size, x, y, (dir ^ 2));
            solve(idx, size, x, y + (1 << size), dir);
            solve(idx, size, x + (1 << size), y + (1 << size), dir);
            solve(idx, size, x + (1 << size), y, (dir ^ 1));
        }
        if (dir == 3)
        {
            solve(idx, size, x + (1 << size), y + (1 << size), (dir ^ 2));
            solve(idx, size, x, y + (1 << size), dir);
            solve(idx, size, x, y, dir);
            solve(idx, size, x + (1 << size), y, (dir ^ 1));
        }
    }
}

signed main()
{
    fast;
    cin >> N;
    if(N == 0)
    {
        cout << 0 << '\n';
        return 0;
    }
    solve(i, N, 0, 0, 0);
    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j < (1 << N); j++)
            cout << arr[i][j] << " \n"[j == (1 << N) - 1];
}