#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200015
using namespace std;
int n, k, arr[2*N];
set<int> can_move;
set<pii>val;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        val.clear();
        can_move.clear();
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            arr[i + n] = 1e18;
        }
        for (int i = 1; i <= k; i++)
        {
            val.insert({arr[i], i});
        }
        for (int i = 1; i <= n-k+1; i++)
        {
            pii now = *val.begin();
            can_move.insert(min(i + k - 1,n));
            auto it = can_move.lower_bound(now.y);
            if (now.y == i || it == can_move.end())
            {
                val.erase(val.begin());
            }
            else
            {
                // cout<<"work "<<now.y<<" "<<arr[i]<<" "<<arr[now.y]<<'\n';
                can_move.erase(it);
                val.erase(now);
                val.erase({arr[i], i});
                swap(arr[i], arr[now.y]);
                val.insert({arr[now.y], now.y});
            }
            val.insert({arr[i + k], i + k});

            // cout<<"after "<<i<<" : "; 
            // for (auto j:val){
            //     cout<<j.x<<','<<j.y<<" ";
            // }
            // cout<<'\n';
        }
        for (int i=n-k+2;i<=n;i++){
            pii now=*val.begin();
            if (i==now.y) val.erase(now);
            else if (i!=now.y&&!can_move.empty()){
                val.erase({arr[i],i});
                val.erase(now);
                swap(arr[i],arr[now.y]);
                val.insert({arr[now.y],now.y});
                can_move.erase(can_move.begin());
            }
        }
        for (int i = 1; i <= n; i++)
            cout << arr[i] << " \n"[i == n];
    }
}