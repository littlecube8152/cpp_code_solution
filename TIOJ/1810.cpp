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
#define pdd pair<double, double>
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

const int base = 8;

long long N, ans, mxCode = 0;
map<ll, int> dp[11][11];
vector<int> state[11][11];

inline long long encode(vector<int> &state, int &side)
{
    // convert to lexigraphically smallest
    int convert[base] = {}, idx = 0;
    for (int &i : state)
        if (i != 0 && convert[i] != 0)
            i = convert[i];
        else if (i != 0 && convert[i] == 0)
        {
            convert[i] = ++idx;
            i = convert[i];
        }

    if (side != 0 && convert[side] != 0)
        side = convert[side];
    else if (side != 0 && convert[side] == 0)
    {
        convert[side] = ++idx;
        side = convert[side];
    }

    int code = side;
    reverse(state.begin(), state.end());
    for (int i : state)
        code = code * base + i;
    mxCode = max(mxCode, code);
    return code;
}

inline pair<vector<int>, int> decode(int code)
{
    vector<int> state(N);
    int side;
    for (int i = 0; i < N; i++)
    {
        state[i] = code % base;
        code /= base;
    }
    return make_pair(state, code);
}

signed main()
{
    //fast;

    while (cin >> N)
    {
        ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dp[i][j].clear(), state[i][j].clear();
        dp[N][0].clear();

        state[0][0].emplace_back(1);
        dp[0][0][1] = 1;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                sort(state[i][j].begin(), state[i][j].end());
                state[i][j].resize(unique(state[i][j].begin(), state[i][j].end()) - state[i][j].begin());

                for (int mask : state[i][j])
                {

                    pair<vector<int>, int> code = decode(mask);
                    if (code.S == code.F[j] && code.S != 0)
                        continue;
                    if (j == 0)
                        assert(code.S == 0);

                    //cout << "DP " << i << " " << j << " | ";
                    //for (int i : code.F)
                    //    cout << i << " ";
                    //cout << "| " << code.S << " | " << dp[i][j][mask] << '\n';

                    // case 1 : |
                    //          |
                    if (code.F[j] != 0 && code.S == 0)
                    {
                        //cout << "[1] ";
                        state[i + (j == N - 1)][j + 1 == N ? 0 : j + 1].emplace_back(mask);
                        dp[i + (j == N - 1)][j + 1 == N ? 0 : j + 1][mask] += dp[i][j][mask];
                    }
                    // case 2 : --
                    //
                    if (code.F[j] == 0 && code.S != 0 && j != N - 1)
                    {
                        //cout << "[2] ";
                        state[i + (j == N - 1)][j + 1 == N ? 0 : j + 1].emplace_back(mask);
                        dp[i + (j == N - 1)][j + 1 == N ? 0 : j + 1][mask] += dp[i][j][mask];
                    }
                    // case 3 : |
                    //          |--
                    if (code.F[j] != 0 && code.S == 0 && j != N - 1)
                    {
                        //cout << "[3] ";
                        int newtype = base - 1;
                        for (int k = 0; k < N; k++)
                            if (k != j && code.F[k] == code.F[j])
                                code.F[k] = newtype;

                        code.S = newtype;
                        code.F[j] = 0;

                        int newmask = encode(code.F, code.S);
                        state[i + (j == N - 1)][j + 1 == N ? 0 : j + 1].emplace_back(newmask);
                        dp[i + (j == N - 1)][j + 1 == N ? 0 : j + 1][newmask] += dp[i][j][mask];
                    }
                    // case 4 : |--
                    //          |
                    else if (code.F[j] == 0 && code.S == 0 && j != N - 1)
                    {
                        //cout << "[4] ";
                        int newtype = base - 1;
                        code.F[j] = newtype;
                        int newmask = encode(code.F, newtype);
                        state[i + (j == N - 1)][j + 1 == N ? 0 : j + 1].emplace_back(newmask);
                        dp[i + (j == N - 1)][j + 1 == N ? 0 : j + 1][newmask] += dp[i][j][mask];
                    }
                    // case 5 : --|
                    //            |
                    else if (code.F[j] == 0 && code.S != 0)
                    {
                        //cout << "[5] ";
                        int newtype = base - 1;

                        for (int k = 0; k < N; k++)
                            if (code.F[k] == code.S)
                                code.F[k] = newtype;
                        code.F[j] = newtype;
                        code.S = 0;
                        int newmask = encode(code.F, code.S);
                        state[i + (j == N - 1)][j + 1 == N ? 0 : j + 1].emplace_back(newmask);
                        dp[i + (j == N - 1)][j + 1 == N ? 0 : j + 1][newmask] += dp[i][j][mask];
                    }
                    // case 6 :   |
                    //          --|
                    else if (code.F[j] != 0 && code.S != 0 && code.F[j] != code.S)
                    {
                        //cout << "[6] ";
                        int newtype = code.F[j], changetype = code.S;
                        code.F[j] = 0;
                        code.S = 0;
                        for (int k = 0; k < N; k++)
                            if (code.F[k] == changetype)
                                code.F[k] = newtype;

                        int newmask = encode(code.F, code.S);
                        state[i + (j == N - 1)][j + 1 == N ? 0 : j + 1].emplace_back(newmask);
                        dp[i + (j == N - 1)][j + 1 == N ? 0 : j + 1][newmask] += dp[i][j][mask];
                    }
                    // cout << '\n';
                }
                dp[i][j].clear(), state[i][j].clear();
            }
        cout << dp[N][0][1] << '\n';
    }
    //cout << mxCode << '\n';
}
