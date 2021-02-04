#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
vector<int> e[10005], re[10005];
queue<int> q;
int deg[10005] = {0};
bool s[10005] = {0};

int main()
{
    fast;
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            return 0;
        for (int i = 0; i <= n; i++)
            e[i] = {}, re[i] = {}, q = {}, deg[i] = 0, s[i] = 0;

        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            e[x].emplace_back(y);
            re[y].emplace_back(x);
            deg[x]++;
        }
        q.push(n);
        while (!q.empty())
        {
            for (auto i : re[q.front()])
            {
                deg[i]--;
                if (!deg[i])
                    q.push(i);
            }
            for (auto i : e[q.front()])
                s[q.front()] |= !s[i];
            q.pop();
        }
        string str;
        cin >> str;
        if (str == "Mimi")
        {
            if (!s[1])
                cout << "Mimi\n";
            else
                cout << "Moumou\n";
        }
        else if (!s[1])
            cout << "Moumou\n";
        else
            cout << "Mimi\n";
    }
}