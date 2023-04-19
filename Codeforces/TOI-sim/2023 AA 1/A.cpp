#include <bits/stdc++.h>
using namespace std;

int N, A, B, p[200005], q[200005], s[200005], vis[200005];
vector<int> ans;

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> p[i];
    cin >> A;
    for (int i = 1; i <= N; i++)
    {
        char c;
        cin >> c;
        if (c == '1')
            s[p[i]] ^= 1;
    }

    for (int i = 1; i <= N; i++)
        cin >> q[i];
    cin >> B;
    for (int i = 1; i <= N; i++)
    {
        char c;
        cin >> c;
        if (c == '1')
            s[q[i]] ^= 2;
    }

    set<int> dupe;
    for (int i = 1; i <= A; i++)
        vis[p[i]] ^= 1, s[p[i]] ^= 1;
    for (int i = 1; i <= B; i++)
    {
        vis[q[i]] ^= 2, s[q[i]] ^= 2;
        if (vis[q[i]] == 3)
            dupe.insert(q[i]);
    }
    int adx = A + 1, bdx = B + 1;
    while (!dupe.empty())
    {
        int i = *dupe.begin();
        ans.emplace_back(i);
        dupe.erase(dupe.begin());
        if (s[i] == 3)
        {
            cout << -1 << '\n';
            return 0;
        }
        else if (s[i] == 2)
        {
            s[i] ^= 2;
            vis[q[bdx]] ^= 2, s[q[bdx]] ^= 2;
            if (vis[q[bdx]] == 3)
                dupe.insert(q[bdx]);
            bdx++;
        }
        else if (s[i] == 1)
        {
            s[i] ^= 1;
            vis[p[adx]] ^= 1, s[p[adx]] ^= 1;
            if (vis[p[adx]] == 3)
                dupe.insert(p[adx]);
            adx++;
        }
    }
    for (int i = 1; i <= N; i++)
        if (s[i])
        {
            cout << -1 << "\n";
            return 0;
        }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    if (ans.empty())
        cout << '\n';
}
