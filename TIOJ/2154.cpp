#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> st, allst;
    for (int i = 'a'; i <= 'z'; i++)
        allst.insert(i);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        st.clear();

        for (int j = 0; j < s.length(); j++)
            st.insert((int)s[j]);

        for (int j = 'a'; j <= 'z'; j++)
            if (!st.count(j) && allst.count(j))
                allst.erase(j);
    }
    if (allst.empty())
        cout << "7122\n";
    else
        cout << (char)*allst.begin() << '\n';
}