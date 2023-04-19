#include <bits/extc++.h>
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;

int N, M, frame[100005];
pii pic[100005];
tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> st;

signed main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> pic[i].S >> pic[i].F;
    for (int i = 1; i <= M; i++)
        cin >> frame[i];
    sort(pic + 1, pic + 1 + N);
    sort(frame + 1, frame + 1 + M);
    for (int i = 1; i <= M; i++)
        st.insert({i, N});
    for (int i = 1; i <= N; i++)
    {
        cout << '\n';
        auto idx = lower_bound(frame + 1, frame + 1 + M, pic[i].S) - frame;
        if (idx <= M)
        {
            int aidx = st.find_by_order(idx - 1)->F;
            st.insert({aidx, N - i});
            st.erase(prev(st.end()));
        }
    }
    int cnt = 0;
    for(auto [_, i] : st)
        if(i < N)
            cnt++;
    cout << (cnt) << '\n';
}