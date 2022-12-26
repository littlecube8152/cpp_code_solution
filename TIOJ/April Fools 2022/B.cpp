#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

char c(char c)
{
    return c - 'a';
}

struct node
{
    int child[26] = {};
};
node trie[40000];

int N, idx = 1, T;
ll ans = 0;

void go(string &s, int i, int tidx)
{
    // cout << "go " << s << " " << i << " " << tidx << "\n";
    if (i + 1 < s.size())
    {
        if (trie[tidx].child[c(s[i + 1])] == 0)
            trie[tidx].child[c(s[i + 1])] = ++idx;
        go(s, i + 1, trie[tidx].child[c(s[i + 1])]);
    }
}

void dfs(int i, int dep)
{
    if (dep == 5)
        return;
    for (int c = 0; c < 26; c++)
    {
        cout << (trie[i].child[c] ? 0 : 1);
        if (trie[i].child[c])
            dfs(trie[i].child[c], dep + 1);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    while (cin >> s)
    {
        s = " " + s;
        go(s, 0, 1);
    }
    dfs(1, 0);
}
