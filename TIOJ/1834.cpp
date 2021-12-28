#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string fill(string s)
{
    return string(1002 - s.length(), ' ') + s;
}

string trim(string s)
{
    int i = 0;
    while (s[i] != ' ')
        i++;
    return s.substr(i, s.length() - i);
}

signed main()
{
    fast;
    int n;
    while (cin >> n)
    {
        string s;
        stack<string> A;
        queue<string> B;
        priority_queue<string> C;
        priority_queue<string, vector<string>, greater<string>> D;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            if (s == "ダメよ～ダメダメ")
            {
                int x;
                string y;
                cin >> x >> y;
                if (x == 1)
                    A.push(fill(y));
                if (x == 2)
                    B.push(fill(y));
                if (x == 3)
                    C.push(fill(y));
                if (x == 4)
                    D.push(fill(y));
            }
            if (s == "しかしお兄ちゃんはわりと弱気だからなぁ……アタシの方からアプローチしないとダメかな")
            {
                int x, y;
                cin >> x >> y;
                switch(x * y)
                {

                }
            }
        }
    }
}