#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int T, N, M, K, f[100005], cnt[10004], vis[100005];
set<int> cur[10004];
void solve()
{
    cin >> M >> N >> K;
    for (int i = 1; i <= M; i++)
    {
        cur[i].clear();
        cnt[i] = 0;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> f[i];
        cnt[f[i]]++;
        vis[i] = 0;
    }
    vector<int> up;
    map<int, int> mp;
    int sz = K, ldx = 1, rdx = K + 1;
    for (int i = 1; i < rdx; i++)
    {
        //cout << "in " << i << '\n';
        if (1 <= f[i] && f[i] <= K)
        {
            //cout << "pop in\n";
            rdx = min(rdx + 1, N + 1);
            cnt[f[i]]--;
            vis[i] = 1;
        }
        else
        {
            cur[f[i]].insert(i);
            mp[f[i]]++;
        }
    }
    //cout << "init\n";
    for (int i = 1; i <= M; i++)
    {
        //cout << "check " << i << '\n';
        sz -= mp[i + K - 1];
        cnt[i + K - 1] -= mp[i + K - 1];
        for(int j : cur[i + K - 1])
            vis[j] = 1;
        cur[i + K - 1].clear();
        mp[i + K - 1] = 0;
        while (rdx <= N && sz < K)
        {
            //cout << "in " << rdx << '\n';
            if (i <= f[rdx] && f[rdx] < i + K)
            {
                //cout << "pop in\n";
                cnt[f[rdx]]--;
                vis[rdx] = 1;
            }
            else
            {
                cur[f[rdx]].insert(rdx);
                mp[f[rdx]]++;
                sz++;
            }
            rdx++;
        }
        while (!up.empty() && sz < K)
        {
            //cout << "in(up) " << up.back() << '\n';
            if (i <= f[up.back()] && f[up.back()] < i + K)
            {
                //cout << "pop in\n";
                cnt[f[up.back()]]--;
                vis[up.back()] = 1;
            }
            else
            {
                cur[f[up.back()]].insert(up.back());
                mp[f[up.back()]]++;
                sz++;
            }
            up.pop_back();
        }
        bool change = 1;
        while (cnt[i] > 0 && change)
        {
            change = 0;
            if (rdx <= N)
            {
                while (vis[ldx])
                    ldx++;
                mp[f[ldx]]--;
                sz--;
                up.emplace_back(ldx);
                //cout << "out " << ldx << '\n';
                cur[f[ldx]].erase(ldx);
                ldx++;
                while (rdx <= N)
                {
                    //cout << "in " << rdx << '\n';
                    if (i <= f[rdx] && f[rdx] < i + K)
                    {
                        //cout << "pop in\n";
                        cnt[f[rdx]]--;
                        vis[rdx] = 1;
                        rdx++;
                    }
                    else
                    {
                        cur[f[rdx]].insert(rdx);
                        mp[f[rdx]]++;
                        sz++;
                        rdx++;
                        break;
                    }
                }
                if (sz < K)
                    while (!up.empty() && sz < K)
                    {
                        //cout << "in(up) " << up.back() << '\n';
                        if (i <= f[up.back()] && f[up.back()] < i + K)
                        {
                            //cout << "pop in\n";
                            cnt[f[up.back()]]--;
                            vis[up.back()] = 1;
                        }
                        else
                        {
                            cur[f[up.back()]].insert(up.back());
                            mp[f[up.back()]]++;
                            sz++;
                        }
                        up.pop_back();
                    }
                change = 1;
            }
        }
        if (cnt[i] > 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main()
{
    // ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
        solve();
}