#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

const ll MOD = 1000000007;
map<int, int> mp;
int dp[100005][2] = {{0}};

void valid(int x)
{

    while ((x == 1 && mp.find(1) != mp.end() && mp[1] >= 2) || (mp.find(x) != mp.end() && mp.find(x + 1) != mp.end()))
    {
        if (x == 1 && mp.find(1) != mp.end() && mp[1] >= 2)
        {
            mp[x + 1] += mp[x] / 2;
            mp[x] %= 2;
            if (mp[x] == 0)
                mp.erase(mp.find(x));
        }
        else if (mp[x] < mp[x + 1])
        {
            mp[x + 2] += mp[x];
            mp[x + 1] -= mp[x];
            mp.erase(mp.find(x));
        }
        else if (mp[x] == mp[x + 1])
        {
            mp[x + 2] += mp[x];
            mp.erase(mp.find(x + 1));
            mp.erase(mp.find(x));
        }
        else
        {
            mp[x + 2] += mp[x + 1];
            mp[x] -= mp[x + 1];
            mp.erase(mp.find(x + 1));
        }
        x++;
        if (!(x == 1 && mp.find(1) != mp.end() && mp[1] >= 2) || (mp.find(x) != mp.end() && mp.find(x + 1) != mp.end()))
            x++;
    }
    if (mp.find(2) != mp.end() && mp[2] >= 2)
    {
        mp[3] += 2 * (mp[2] / 3);
        mp[2] %= 3;
        if (mp[2] == 2)
        {
            mp[3]++, mp[1]++;
            mp[2] = 0;
        }
        if (mp[2] == 0)
            mp.erase(mp.find(2));
    }
}

signed main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
        valid(x);
        valid(x - 1);

        valid(1);
        valid(3);
        auto iter = mp.begin();
        if (iter->S >= 3)
            dp[1][0] = dp[1][1] = 0;
        else if (iter->S == 2)
        {
            if (iter->F >= 3)
                dp[1][1] = (iter->F - 1) / 2;
            else
                dp[1][1] = 0;
            dp[1][0] = 0;
        }
        else
        {
            dp[1][1] = (iter->F - 1) / 2;
            dp[1][0] = 1;
        }
        ++iter;

        for (int i = 2; i <= mp.size(); i++)
        {
            if (iter->S >= 3)
                dp[i][0] = dp[i][1] = 0;
            else if (iter->S == 2 && prev(iter)->S == 2)
            {
                dp[i][1] = (dp[i - 1][1] * ((iter->F - prev(iter)->F - 1) / 2)) % MOD;
                dp[i][0] = 0;
            }
            else if (iter->S == 2 && prev(iter)->S == 1)
            {
                dp[i][1] = (dp[i - 1][1] * ((iter->F - prev(iter)->F) / 2) +
                            dp[i - 1][0] * ((iter->F - prev(iter)->F - 1) / 2)) %
                           MOD;
                dp[i][0] = 0;
            }
            else if (iter->S == 1 && prev(iter)->S == 2)
            {
                dp[i][1] = dp[i - 1][1] * ((iter->F - prev(iter)->F - 1) / 2) % MOD;
                dp[i][0] = dp[i - 1][1];
            }
            else if (iter->S == 1 && prev(iter)->S == 1)
            {
                dp[i][1] = (dp[i - 1][1] * ((iter->F - prev(iter)->F) / 2) +
                            dp[i - 1][0] * ((iter->F - prev(iter)->F - 1) / 2)) %
                           MOD;
                dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
            }
            ++iter;
        }
        //for (pii i : mp)
        //    cout << "(" << i.F << ", " << i.S << ") ";
        cout << (dp[mp.size()][0] + dp[mp.size()][1]) % MOD << '\n';
    }
}

/*
1 = 1
2 = 2
3 = 1 + 2, 3
4 = 1 + 3
5 = 2 + 3, 5
6 = 5 + 1, 1 + 2 + 3
7 = 5 + 2, 
8 = 5 + 3, 8, 1 + 2 + 5,
 
*/