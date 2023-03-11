#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

const int C = 62;
const ll mod = 998'244'353;
int N;
vector<string> v[11];
ll ans, way[C][C][C], edge[C][C], mul[2][2][2];

int id(char c)
{
    if ('a' <= c && c <= 'z')
        return c - 'a';
    else if ('A' <= c && c <= 'Z')
        return c - 'A' + 26;
    else
        return c - '0' + 52;
}

signed main()
{
    cin >> N;
    mul[0][0][0] = 24;
    mul[1][0][0] = mul[0][1][0] = mul[0][0][1] = 12;
    mul[1][1][0] = mul[0][1][1] = 4;
    mul[1][0][1] = 6;
    mul[1][1][1] = 1;

    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        v[s.size()].emplace_back(s);
        reverse(s.begin(), s.end());
        v[s.size()].emplace_back(s);
    }
    for (int s = 3; s <= 10; s++)
    {
        sort(v[s].begin(), v[s].end());
        v[s].resize(unique(v[s].begin(), v[s].end()) - v[s].begin());
        for (int i = 0; i < C; i++)
            for (int j = i; j < C; j++)
                for (int k = j; k < C; k++)
                    way[i][j][k] = 0;
        for (int i = 0; i < C; i++)
            for (int j = 0; j < C; j++)
                edge[i][j] = 0;

        for (auto t : v[s])
            edge[id(t.front())][id(t.back())]++;

        for (int i = 0; i < C; i++)
            for (int j = i; j < C; j++)
                for (int k = j; k < C; k++)
                    for (int l = 0; l < C; l++)
                        way[i][j][k] = (way[i][j][k] + edge[l][i] * edge[l][j] % mod * edge[l][k]) % mod;

        for (int i = 0; i < C; i++)
            for (int j = i; j < C; j++)
                for (int k = j; k < C; k++)
                    for (int l = k; l < C; l++)
                        ans = (ans + way[i][j][k] * way[i][j][l] % mod * way[i][k][l] % mod * way[j][k][l] % mod * mul[i == j][j == k][k == l]) % mod;
    }
    cout << ans << '\n';
}
