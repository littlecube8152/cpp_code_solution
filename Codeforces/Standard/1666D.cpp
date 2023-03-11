#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define x first
#define S second
#define y second
using namespace std;

void solve()
{
	string s, t;
	cin >> s >> t;
	map<char, bool> mp;
	while(!s.empty() && !t.empty())
	{
		if(mp[s.back()])
			s.pop_back();
		else if(s.back() == t.back())
		{
			s.pop_back();
			t.pop_back();
		}
		else
		{
			mp[s.back()] = 1;
			s.pop_back();
		}	
	}
	cout << (t.empty() ? "YES\n" : "NO\n");
}

signed main()
{
	int t;
	cin >> t;
	while(t--)
		solve();

} 
