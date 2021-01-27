//
//
//Not Solved Yet
//
//
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct Node
{
    vector<int> forward;
    vector<int> backward;
    bool visited = 0;
    int deg = 0;
    string str;
    int max = 0;
};

bool comp(Node n1, Node n2)
{
    return n1.deg > n2.deg;
}

Node node[300005];
queue<int> q;
ll n, m;
string s;

int main()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        node[x].forward.emplace_back(y);
        node[x].deg++;
        node[y].backward.emplace_back(x);
    }
    sort(node + 1, node + n + 1, comp);

    for (int i = n; i > 0; i--)
    {
        if (node[i].deg == 0)
            q.push(i);
        else
            break;
    }
    while(!q.empty())
    {
        
    }
    return 0;
}