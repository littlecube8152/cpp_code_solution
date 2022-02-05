#include <iostream>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, q, d[200005];

int find(int k)
{
    if (k != d[k])
        return find(d[k]);
    else
        return k;
}

void merge_find(int k, int root)
{
    if (k != d[k])
        merge_find(d[k], root);
    d[k] = root;
}

int main()
{
    fast;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        d[i] = i;
    while (q--)
    {
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1)
            d[y] = find(x);
        else if (t == 2)
        {
            int root = find(x);
            for (int i = x + 1; i <= y; i++)
                merge_find(i, root);
        }
        else
        {
            if (find(x) == find(y))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}