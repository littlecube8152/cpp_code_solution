#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n;
string s;

signed main()
{
    fast;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        cin >> s;

        set<char> st;
        map<char, int> mp;
        ll left = 0, right = -1, minlen = 10000000000, minleft, minright;

        while (left < n)
        {
            if (st.size() < 26 && right < n - 1)
            {
                right++;
                mp[s[right]]++;
                st.insert(s[right]);
            }
            else
            {
                mp[s[left]]--;
                if (mp[s[left]] == 0)
                    st.erase(s[left]);
                left++;
            }

            if (st.size() == 26)
                if (right - left + 1 < minlen)
                {
                    minlen = right - left + 1;
                    minleft = left;
                    minright = right;
                }
        }
        if (minlen > n)
            cout << "not found\n";
        else
            cout << s.substr(minleft, minright - minleft + 1) << '\n';
    }
}
