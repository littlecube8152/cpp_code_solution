#include <bits/extc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;

ll N, Q, water[100005];
tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> arr;

signed main()
{
    cin >> N;
    for (int i = 1; i <= N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> water[i];
        arr.insert(pll{i, water[i]});
    }
    arr.insert(pll{0, 0});
    arr.insert(pll{N + 1, 0});
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int v;
        ll newwater = 0, newpos;
        cin >> v;
        newpos = arr.find_by_order(v)->F;
        cout << arr.find_by_order(v)->S << " \n"[i == Q];
        arr.erase(arr.find_by_order(v));
        newwater += arr.find_by_order(v - 1)->S;
        newwater += arr.find_by_order(v)->S;
        arr.erase(arr.find_by_order(v));
        arr.erase(arr.find_by_order(v - 1));
        arr.insert(pll{newpos, newwater});
        arr.insert(pll{-i, 0});
        arr.insert(pll{N + i + 1, 0});
    }
}