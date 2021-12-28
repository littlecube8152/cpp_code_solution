#include <bits/stdc++.h>
using namespace std;

int idx, N;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s >> idx >> N;
    queue<int> st;
    vector<int> v(N);
    vector<int> ans;
    for (int i = 0; i < N; i++)
        v[i] = i + 1;
    for (int i = 1; i <= N; i++)
    {
        int x, up = 0;
        cin >> x;
        for (;; up++)
        {
            if (v[up] == x)
                break;
        }
        for (int j = up; j >= i; j--)
            ans.emplace_back(j);
        v.erase(v.begin() + up);
        v.insert(v.begin(), 0);
    }
    cout << s << " " << idx << '\n';
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
}